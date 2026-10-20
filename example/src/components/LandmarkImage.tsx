import { useEffect, useMemo, useState } from 'react';

type Point = { x: number; y: number };

type Props = {
  uri: string | null | undefined;
  landmarks: Point[];
  imageSize?: { w: number; h: number };
  width: number;
  height: number;
};

/**
 * Landmarks must be in the displayed image's pixel space (cropFace bitmap),
 * not full camera-frame coords — otherwise dots pile at the bottom-right.
 */
export default function LandmarkImage({
  uri,
  landmarks,
  imageSize,
  width,
  height,
}: Props) {
  const [nat, setNat] = useState(imageSize ?? { w: 0, h: 0 });

  useEffect(() => {
    setNat(imageSize && imageSize.w > 0 && imageSize.h > 0 ? imageSize : { w: 0, h: 0 });
  }, [uri, imageSize]);

  const space = useMemo(() => {
    if (imageSize && imageSize.w > 0 && imageSize.h > 0) return imageSize;
    if (nat.w > 0 && nat.h > 0) return nat;
    // No size yet — hide dots (avoid mapping full-frame xy onto a fake 200×200).
    return { w: 0, h: 0 };
  }, [nat, imageSize]);

  const mapped = useMemo(() => {
    if (!landmarks.length || space.w <= 0 || space.h <= 0) return [];
    // Drop full-frame coords accidentally passed for a small crop.
    const maxX = Math.max(...landmarks.map((p) => p.x));
    const maxY = Math.max(...landmarks.map((p) => p.y));
    if (maxX > space.w * 1.25 || maxY > space.h * 1.25) return [];
    const scale = Math.min(width / space.w, height / space.h);
    const dx = (width - space.w * scale) / 2;
    const dy = (height - space.h * scale) / 2;
    return landmarks.map((p) => ({
      x: p.x * scale + dx,
      y: p.y * scale + dy,
    }));
  }, [landmarks, space, width, height]);

  return (
    <div className="landmark-image" style={{ width, height }}>
      {uri ? (
        <img
          alt=""
          src={uri}
          onLoad={(e) => {
            const el = e.currentTarget;
            if (el.naturalWidth > 0 && el.naturalHeight > 0) {
              setNat({ w: el.naturalWidth, h: el.naturalHeight });
            }
          }}
        />
      ) : null}
      {mapped.map((pt, i) => (
        <div key={i} className="landmark-dot" style={{ left: pt.x - 4, top: pt.y - 4 }}>
          <span>{i + 1}</span>
        </div>
      ))}
    </div>
  );
}
