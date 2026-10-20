//
//  FaceLivenessSDK.h
//  facelivenesssdk.framework
//
//  Identixia FaceLivenessSDK for iOS (product 741777).
//  Public API mirrors FaceRecognition-Linux (detect, quality, match, feature).
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

FOUNDATION_EXPORT double facelivenesssdkVersionNumber;
FOUNDATION_EXPORT const unsigned char facelivenesssdkVersionString[];

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, FaceLivenessSDKError) {
    FaceLivenessSDKSuccess = 0,
    FaceLivenessSDKLicenseInvalid = 1,
    FaceLivenessSDKLicenseExpired = 2,
    FaceLivenessSDKNotActivated = 3,
    FaceLivenessSDKInitFailed = 4,
};

/** Face box is always returned; these bits select which estimators run this frame. */
typedef NS_OPTIONS(NSUInteger, FaceRecognitionDetectFlags) {
    FaceRecognitionDetectPose = 1 << 0,
    FaceRecognitionDetectLandmarks = 1 << 1,
    FaceRecognitionDetectAge = 1 << 2,
    FaceRecognitionDetectGender = 1 << 3,
    FaceRecognitionDetectEmotion = 1 << 4,
    FaceRecognitionDetectMask = 1 << 5,
    FaceRecognitionDetectQuality = 1 << 6,
    FaceRecognitionDetectFaceQuality = 1 << 7,
    FaceRecognitionDetectEyes = 1 << 8,
    FaceRecognitionDetectLiveness = 1 << 9,
    FaceRecognitionDetectGlasses = 1 << 11,
    /** Still-image deepfake estimator (needs a fitted face). */
    FaceRecognitionDetectDeepfake = 1 << 12,
    /** With DETECT_LIVENESS: High Accuracy pack (2d_ensemble_heavy). */
    FaceRecognitionDetectLivenessAccurate = 1 << 16,
    FaceRecognitionDetectAll = NSUIntegerMax,
};

/** Capture / detect landmark density: 14 = FDA (filtered), 68 = tddfa, 468 = mesh. */
typedef NS_ENUM(int, FaceRecognitionLandmarkMode) {
    FaceRecognitionLandmarkMode14 = 14,
    FaceRecognitionLandmarkMode68 = 68,
    FaceRecognitionLandmarkMode468 = 468,
};

/** Active liveness challenge types for VideoWorker (Enroll / Identity). */
typedef NS_ENUM(NSInteger, FaceRecognitionActiveLivenessCheck) {
    FaceRecognitionActiveLivenessCheckSmile = 1,
    FaceRecognitionActiveLivenessCheckBlink = 2,
    FaceRecognitionActiveLivenessCheckTurnUp = 3,
    FaceRecognitionActiveLivenessCheckTurnDown = 4,
    FaceRecognitionActiveLivenessCheckTurnRight = 5,
    FaceRecognitionActiveLivenessCheckTurnLeft = 6,
    FaceRecognitionActiveLivenessCheckPerspective = 7,
};

__attribute__((visibility("default")))
@interface FaceRecognitionActiveLivenessConfig : NSObject
@property (nonatomic, assign) BOOL enabled;
/** Ordered unique checks (smile / blink / turn*). Empty = SDK default order when enabled. */
@property (nonatomic, copy) NSArray<NSNumber *> *checks;
@property (nonatomic, assign) float smileThreshold;
@property (nonatomic, assign) float blinksThreshold;
@property (nonatomic, assign) NSInteger blinksNumber;
@property (nonatomic, assign) float yawThreshold;
@property (nonatomic, assign) float pitchThreshold;
@property (nonatomic, assign) float perspectiveThreshold;
@property (nonatomic, assign) float faceAlignAngle;
@property (nonatomic, assign) NSInteger maxFramesWait;
@property (nonatomic, assign) NSInteger checkCount;
+ (instancetype)defaultConfig;
@end

__attribute__((visibility("default")))
@interface FaceRecognitionVideoWorkerConfig : NSObject
@property (nonatomic, assign) float matchThreshold;
@property (nonatomic, strong) FaceRecognitionActiveLivenessConfig *activeLiveness;
+ (instancetype)configWithMatchThreshold:(float)threshold;
@end

__attribute__((visibility("default")))
@interface FaceLivenessSDK : NSObject

+ (int)SDK_SUCCESS;
+ (int)SDK_LICENSE_INVALID;
+ (int)SDK_LICENSE_EXPIRED;
+ (int)SDK_NOT_ACTIVATED;
+ (int)SDK_INIT_FAILED;

/** Machine code for this install (…). Fingerprint is SHA256("IOS|" + exact bundleId). */
+ (NSString *)getMachineCode;

/** Activate with … for product 741777 (FaceLivenessSDK). */
+ (int)setActivation:(NSString *)license;

+ (NSString *)lastLicenseError;
+ (BOOL)isActivated;
+ (NSString *)getLicenseStatus;
+ (BOOL)allowsRecognition;
+ (BOOL)allowsLiveness;

/** Decrypt runtime data and load models. Call off the main thread on first run. */
+ (int)initSDK;

/** 14 = FDA (14 pts), 68 = tddfa full, 468 = mesh full. */
+ (int)setLandmarkMode:(int)mode;
+ (int)landmarkMode;

/** Detect faces + attributes. Returns JSON string (Linux-compatible). */
+ (nullable NSString *)detectImage:(UIImage *)image crop:(BOOL)crop
    NS_SWIFT_NAME(detectImage(_:crop:));

/** Detect faces, running only the estimators in `flags` (faster for live camera). */
+ (nullable NSString *)detectImage:(UIImage *)image crop:(BOOL)crop flags:(FaceRecognitionDetectFlags)flags
    NS_SWIFT_NAME(detectImage(_:crop:flags:));

/** ICAO-style quality assessment JSON. */
+ (nullable NSString *)qualityImage:(UIImage *)image crop:(BOOL)crop;

/** 1:1 match JSON with similarity score. */
+ (nullable NSString *)matchImage1:(UIImage *)image1 image2:(UIImage *)image2 crop:(BOOL)crop;

/** Extract face template/feature JSON. */
+ (nullable NSString *)extractFeatureFromImage:(UIImage *)image;

/** Which attribute estimators loaded at init (JSON). */
+ (nullable NSString *)estimatorStatusJSON;

/** Compare two template blobs from extractFeatureFromImage (0–1, or -1 on error). */
+ (float)similarityWithFeature1:(NSData *)feature1 feature2:(NSData *)feature2;

/** Realtime VideoWorker tracking + 1:N matching (enroll/identity). Event JSON on main queue. */
+ (int)startVideoWorkerWithMatchThreshold:(float)threshold;
/** Same as startVideoWorkerWithMatchThreshold: plus optional active liveness config. */
+ (int)startVideoWorkerWithConfig:(FaceRecognitionVideoWorkerConfig *)config;
+ (void)stopVideoWorker;
+ (void)setVideoWorkerEventHandler:(void (^ _Nullable)(NSString *json))handler;
+ (int)syncVideoWorkerDatabaseWithFeatures:(NSArray<NSData *> *)features matchThreshold:(float)threshold;
+ (int)addVideoWorkerFrame:(UIImage *)image;
/** Fast path: feed BGRA camera buffer directly (call from camera queue). */
+ (int)addVideoWorkerSampleBuffer:(CMSampleBufferRef)sampleBuffer;
/** Enroll save: extract template from BGRA sample buffer. */
+ (nullable NSString *)extractFeatureWithSampleBuffer:(CMSampleBufferRef)sampleBuffer;

+ (int)deinitSDK;

// Android FaceLivenessSDK / FaceRecognitionSDK-compatible customer names.
+ (int)getLandmarkMode;
+ (nullable NSString *)detect:(UIImage *)image crop:(BOOL)crop
    NS_SWIFT_UNAVAILABLE("Use detectImage(_:crop:)");
+ (nullable NSString *)detect:(UIImage *)image crop:(BOOL)crop flags:(FaceRecognitionDetectFlags)flags
    NS_SWIFT_UNAVAILABLE("Use detectImage(_:crop:flags:)");
+ (nullable NSString *)faceDetect:(UIImage *)image crop:(BOOL)crop;
+ (nullable NSString *)faceAttribute:(UIImage *)image crop:(BOOL)crop;
+ (nullable NSString *)imageQuality:(UIImage *)image crop:(BOOL)crop;
+ (nullable NSString *)landmarks:(UIImage *)image mode:(int)mode;
+ (nullable NSString *)quality:(UIImage *)image crop:(BOOL)crop;
+ (nullable NSString *)match:(UIImage *)image1 image2:(UIImage *)image2 crop:(BOOL)crop;
+ (nullable NSString *)extractFeature:(UIImage *)image;
+ (nullable NSString *)getFeature:(UIImage *)image;
+ (float)similarity:(NSData *)feature1 feature2:(NSData *)feature2;
+ (nullable NSString *)liveness:(UIImage *)image;
+ (nullable NSString *)livenessAll:(UIImage *)image;
+ (nullable NSString *)deepfake:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
