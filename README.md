<div align="center">
<img alt="Identixia" src="https://raw.githubusercontent.com/identixia-IDV/identixia-assets/main/brand/logo.png" width="320"/>

<a href="https://identixia.com"><img src="https://img.shields.io/badge/Website-0F766E?style=for-the-badge&logo=googlechrome&logoColor=white" alt="Website" /></a>
<a href="https://docs.identixia.com"><img src="https://img.shields.io/badge/Docs-0F766E?style=for-the-badge&logo=gitbook&logoColor=white" alt="Docs" /></a>
<a href="https://huggingface.co/Identixia"><img src="https://img.shields.io/badge/HuggingFace-FFD21E?style=for-the-badge&logo=huggingface&logoColor=black" alt="Hugging Face" /></a>
<a href="https://hub.docker.com/u/identixia"><img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white" alt="Docker Hub" /></a>
<a href="https://playground.identixia.com/"><img src="https://img.shields.io/badge/Playground-0F766E?style=for-the-badge&logo=cloudplayground&logoColor=white" alt="Playground" /></a>
</div>

<div align="center">

# <img src="https://cdn.simpleicons.org/ionic/3880FF" width="32" height="32" alt="" /> Face Liveness Detection SDK for Ionic Capacitor — Plugin and Sample App | Identixia

</div>

Integrate **face liveness detection and anti-spoofing** with the **Identixia Ionic Capacitor SDK**. This repository provides a Ionic Capacitor plugin for Android and iOS for passive face liveness detection and deepfake detection. Use presentation attack detection (PAD) to check for face spoofing and deepfake detection to check for manipulated face images. The combined authenticity result is REAL only when both checks pass. Face recognition and matching are not included.

Use the sample to add selfie liveness checks to remote onboarding and biometric identity verification alongside a separate face matching service. Processing runs on the device; images are not sent to the Identixia cloud.

Package: `face-recognition-capacitor`. Model packs: model files for liveness checks only; face recognition models are not included

<p><img src="https://img.shields.io/badge/On-device-0F766E?style=flat-square" alt="On-device" /> <img src="https://img.shields.io/badge/Passive%20liveness-0F766E?style=flat-square" alt="Passive liveness" /> <img src="https://img.shields.io/badge/Liveness--only-5A6573?style=flat-square" alt="Liveness-only" /> <img src="https://img.shields.io/badge/Android%20%2B%20iOS-0F766E?style=flat-square" alt="Android + iOS" /> <img src="https://img.shields.io/badge/Plugin-5A6573?style=flat-square" alt="Plugin" /></p>

> For setup, integration, and API guides, see the [Face Liveness Detection SDK documentation for Ionic Capacitor](https://docs.identixia.com). This page covers the sample repository.

## <img src="https://api.iconify.design/lucide/clipboard-list.svg?color=%230F766E" width="24" height="24" alt="" /> SDK overview

The sample includes a demo license. Your own application requires a key issued for its application identifier.

| Topic | Basic information |
| --- | --- |
| **Product** | On-device **face liveness detection** Ionic Capacitor plugin |
| **Modes** | Capture · Liveness · Attribute |
| **Packs** | model files for liveness checks only; face recognition models are not included |
| **Runtime** | Local example engines, or the `v1.0.0` GitHub Release when missing |
| **Demo id** | `com.identixia.faceliveness` / `com.identixia.faceliveness.app` |
| **Tools** | Physical **arm64** Android / iPhone |
| **Privacy** | Processing stays on device — no Identixia cloud |

---

## <img src="https://api.iconify.design/lucide/terminal.svg?color=%230F766E" width="24" height="24" alt="" /> Quick start

Choose the instructions for your device below. Run the Android and iOS steps separately; iOS builds require a Mac.

### <img src="https://img.shields.io/badge/-1-0F766E?style=for-the-badge" alt="" /> Clone

```bash
git clone https://github.com/identixia-IDV/FaceLivenessDetection-Ionic-Capacitor.git
cd FaceLivenessDetection-Ionic-Capacitor
```

Download [`libfacelivenesssdk.rar`](https://github.com/identixia-IDV/FaceLivenessDetection-Android/releases/tag/runtime) from the [FaceLivenessDetection-Android Releases](https://github.com/identixia-IDV/FaceLivenessDetection-Android/releases/tag/runtime). Extract it into `example/android/libfacelivenesssdk/`. The files should sit in that folder, not inside an extra directory.

Download [`faceliveness.zip`](https://github.com/identixia-IDV/FaceLivenessDetection-iOS/releases/tag/runtime) from the [FaceLivenessDetection-iOS Releases](https://github.com/identixia-IDV/FaceLivenessDetection-iOS/releases/tag/runtime). Unzip it into `ios/Frameworks/`. The files should sit in that folder, not inside an extra directory.

### Android

`ionic serve` and the browser preview do not load the native engine. Use a physical **arm64** Android phone.

From the repository root:

```bash
npm install
npm run build
cd example
npm install
npm run sync
npm run android
```

`npm run android` opens Android Studio. Select the physical arm64 device and press Run.

### iOS

Use a Mac with Xcode and a physical **iPhone**. `ionic serve` does not load the native engine. Do not use the Simulator for the camera sample.

From the repository root:

```bash
npm install
npm run build
cd example
npm install
npm run sync
npm run ios
```

`npm run ios` opens Xcode. Select the physical iPhone and press Run.

### <img src="https://img.shields.io/badge/-2-0F766E?style=for-the-badge" alt="" /> Activate / license

1. Copy the id of your own app. On Android this is the application id. On iOS this is the bundle id. The sample id is `com.identixia.faceliveness`, `com.identixia.faceliveness.app`.
2. Email that id and the product name to [contact@identixia.com](mailto:contact@identixia.com).
3. Replace the demo key in `example/src/license.ts` with the key you receive.
4. Rebuild, then continue with the next step.

### <img src="https://img.shields.io/badge/-3-0F766E?style=for-the-badge" alt="" /> First capture

Wait for the Home screen to show **Ready**, then choose **Capture** or **Liveness**. Check the license status on the Result or About screen.

---

## <img src="https://api.iconify.design/lucide/list-checks.svg?color=%230F766E" width="24" height="24" alt="" /> Features

| Capability | What it does |
| --- | --- |
| <img src="https://api.iconify.design/lucide/shield.svg?color=%230F766E" width="16" height="16" alt="" /> Passive liveness | Check whether a face is being presented in a spoofing attempt, when licensed |
| <img src="https://api.iconify.design/lucide/shield-alert.svg?color=%230F766E" width="16" height="16" alt="" /> Deepfake | Check for manipulated face images; report REAL only when both liveness and deepfake checks pass |
| <img src="https://api.iconify.design/lucide/aperture.svg?color=%230F766E" width="16" height="16" alt="" /> Capture | Guided still / live capture with quality feedback |
| <img src="https://api.iconify.design/lucide/camera.svg?color=%230F766E" width="16" height="16" alt="" /> Camera | Front/back camera demo for liveness flows |

## <img src="https://api.iconify.design/lucide/pc-case.svg?color=%230F766E" width="24" height="24" alt="" /> System requirements

| | |
| --- | --- |
| Devices | Physical **arm64** Android and/or **iPhone** |
| Package | `face-recognition-capacitor` |
| Demo Android id | `com.identixia.faceliveness` |
| Demo iOS id | `com.identixia.faceliveness.app` |
| Runtimes | Local example engines, or the `v1.0.0` GitHub Release when they are missing |

---

## <img src="https://api.iconify.design/lucide/package.svg?color=%230F766E" width="24" height="24" alt="" /> SDK installation

Download [`libfacelivenesssdk.rar`](https://github.com/identixia-IDV/FaceLivenessDetection-Android/releases/tag/runtime) from the [FaceLivenessDetection-Android Releases](https://github.com/identixia-IDV/FaceLivenessDetection-Android/releases/tag/runtime). Extract it into `example/android/libfacelivenesssdk/`. The files should sit in that folder, not inside an extra directory.

Download [`faceliveness.zip`](https://github.com/identixia-IDV/FaceLivenessDetection-iOS/releases/tag/runtime) from the [FaceLivenessDetection-iOS Releases](https://github.com/identixia-IDV/FaceLivenessDetection-iOS/releases/tag/runtime). Unzip it into `ios/Frameworks/`. The files should sit in that folder, not inside an extra directory.

---

## <img src="https://api.iconify.design/lucide/rocket.svg?color=%230F766E" width="24" height="24" alt="" /> Run

Start in the repository root and follow the commands for your target platform. These commands are also listed in [Quick start](#-quick-start).

**Android** — physical arm64 phone. This opens Android Studio; press Run on that device:

```bash
npm install
npm run build
cd example
npm install
npm run sync
npm run android
```

**iOS** — Mac, Xcode, physical iPhone. This opens Xcode; press Run on that iPhone:

```bash
npm install
npm run build
cd example
npm install
npm run sync
npm run ios
```

---

## <img src="https://api.iconify.design/lucide/key-round.svg?color=%230F766E" width="24" height="24" alt="" /> SDK license and activation

1. Run the sample with the bundled key and the sample id below.
2. For your own app, email [contact@identixia.com](mailto:contact@identixia.com) with the platform, your application id or bundle id, and the features you need.
3. Put the key you receive in the same place as the demo key.
4. Rebuild. Activation runs before SDK init. If it fails, the key does not match that id.

Sample id:

- `com.identixia.faceliveness`
- `com.identixia.faceliveness.app`

Set the key, then activate:

https://github.com/identixia-IDV/FaceLivenessDetection-Ionic-Capacitor/blob/a92bca88db0cd65d534a211e8b17fd65ed814b64/example/src/license.ts#L13-L25

https://github.com/identixia-IDV/FaceLivenessDetection-Ionic-Capacitor/blob/a92bca88db0cd65d534a211e8b17fd65ed814b64/example/src/SdkContext.tsx#L86-L86

## <img src="https://api.iconify.design/lucide/images.svg?color=%230F766E" width="24" height="24" alt="" /> Screenshots

<p align="center">
<img src="https://raw.githubusercontent.com/identixia-IDV/identixia-assets/main/screenshots/face-recognition/android/home.png" width="160" alt="Home" />
<img src="https://raw.githubusercontent.com/identixia-IDV/identixia-assets/main/screenshots/face-recognition/android/capture.png" width="160" alt="Capture" />
<img src="https://raw.githubusercontent.com/identixia-IDV/identixia-assets/main/screenshots/face-recognition/android/enroll.png" width="160" alt="Enroll" />
<img src="https://raw.githubusercontent.com/identixia-IDV/identixia-assets/main/screenshots/face-recognition/android/identify.png" width="160" alt="Identify" />
</p>

## <img src="https://api.iconify.design/lucide/braces.svg?color=%230F766E" width="24" height="24" alt="" /> API

The following SDK methods are used by the sample and can also be called from your application.

| API | Purpose |
| --- | --- |
| `activate(license)` then `init()` | Activate the license, then initialize the engine. Run these calls in order on one background thread. |
| `getLicenseStatus()` | Check the license status and enabled features before opening the camera. |
| `liveness` / `deepfake` | Run presentation attack detection and deepfake checks. Report REAL only when both pass. |
| Enroll / 1:N | Not included. Use a Face Recognition repository for templates. |

Keep camera preview updates on the UI thread. Run SDK operations sequentially on a single background thread; the engine does not support simultaneous calls.

---

## <img src="https://api.iconify.design/lucide/layers.svg?color=%230F766E" width="24" height="24" alt="" /> SDKs for other platforms

| | Platform | Repo |
| --- | --- | --- |
| <img src="https://cdn.simpleicons.org/android/3DDC84" width="18" height="18" alt="" /> | Android | [FaceLivenessDetection-Android](https://github.com/identixia-IDV/FaceLivenessDetection-Android) |
| <img src="https://cdn.simpleicons.org/apple/000000" width="18" height="18" alt="" /> | iOS | [FaceLivenessDetection-iOS](https://github.com/identixia-IDV/FaceLivenessDetection-iOS) |
| <img src="https://cdn.simpleicons.org/flutter/02569B" width="18" height="18" alt="" /> | Flutter | [FaceLivenessDetection-Flutter](https://github.com/identixia-IDV/FaceLivenessDetection-Flutter) |
| <img src="https://cdn.simpleicons.org/react/61DAFB" width="18" height="18" alt="" /> | React Native | [FaceLivenessDetection-React-Native](https://github.com/identixia-IDV/FaceLivenessDetection-React-Native) |
| <img src="https://cdn.simpleicons.org/ionic/3880FF" width="18" height="18" alt="" /> | Ionic Capacitor | [FaceLivenessDetection-Ionic-Capacitor](https://github.com/identixia-IDV/FaceLivenessDetection-Ionic-Capacitor) |
| <img src="https://cdn.simpleicons.org/apachecordova/E8E8E8" width="18" height="18" alt="" /> | Ionic Cordova | [FaceLivenessDetection-Ionic-Cordova](https://github.com/identixia-IDV/FaceLivenessDetection-Ionic-Cordova) |
| <img src="https://cdn.simpleicons.org/windows/0078D4" width="18" height="18" alt="" /> | Windows | [FaceLivenessDetection-Windows](https://github.com/identixia-IDV/FaceLivenessDetection-Windows) |
| <img src="https://cdn.simpleicons.org/docker/2496ED" width="18" height="18" alt="" /> | Linux / Docker | [FaceLivenessDetection-Docker](https://github.com/identixia-IDV/FaceLivenessDetection-Docker) |

---

## <img src="https://api.iconify.design/lucide/mail.svg?color=%230F766E" width="24" height="24" alt="" /> Contact

<div align="center">

<a href="mailto:contact@identixia.com"><img alt="Email contact@identixia.com" src="https://img.shields.io/badge/Email-contact%40identixia.com-0F766E?style=for-the-badge&logo=gmail&logoColor=white" /></a>
<a href="https://wa.me/17018854218"><img alt="WhatsApp +1 (701) 885-4218" src="https://img.shields.io/badge/WhatsApp-%2B1_(701)_885--4218-25D366?style=for-the-badge&logo=whatsapp&logoColor=white" /></a>
<a href="https://t.me/identixia"><img alt="Telegram @identixia" src="https://img.shields.io/badge/Telegram-%40identixia-26A5E4?style=for-the-badge&logo=telegram&logoColor=white" /></a>

</div>

---
