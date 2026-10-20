/**
 * Demo FP1 licenses — same keys as FaceRecognitionSDK Android / iOS Apps.
 * Bound to applicationId / bundle id below. Request a new key if you change the id.
 */
import { Capacitor } from '@capacitor/core';


/** Android + iOS demo applicationId / bundle id */
export const ANDROID_APPLICATION_ID = 'com.identixia.faceliveness';
export const IOS_BUNDLE_ID = 'com.identixia.faceliveness.app';


const ANDROID_LICENSE =
  
  
  'pyyR2AECGJoeK0LxCDt+hl4tn34CmlsQDSy0mQrBc9swF3gAAAD6CMKY7b1+lZx6qKhWZadZPBGVYwRte14RCzmBbQC1YAf4opJwwU2WKRTTRVonXqvSntD5BuLWDAmZu22VmvFDbuyDpY/RCoyHKAOPQb1Y+i6qjy+qJiS2jsRrfoy27VoBKvoWE80ORBO8npwJJUKUlA3VUhfbE+BnADBlAjAPQS01odccQHlQEo1grFk7Ypu2fWISZLs50lXvpT0WpDGQlBuCeeRil4PrXwzYE7YCMQDltz26BbBwfMmT+BmXXR4VUm9AWW2SReW7r7qgFM14jTZsu3sxnrDWTghI5Du3gLI=';


const IOS_LICENSE =
  
  
  'pyyR2AECptG5lGOAzwv+bmiQPrFfO8G6EBX70b61E5BAVHgAAADH64PrYfamj7uclN6rIio4Rto8nEr9IxnxKPwAggo/2uSx+OuqqQgfpTY8c1tD5Hb6v+qrqDXZj2uCTdUYPOL49lJNhOGCUaGLljwUwE8rJ63KHfy2FsyJMqOaBVOYN7pGUok2AXs7+JDWIiD7iVx1oNy4f6ZKNzpnADBlAjAr3SfB6kxRYnomwEyewdMwwouFPQDy4ZwtA4Mz2/SpH5UDV53gmvC701HoARXtF7UCMQDYIUnm97uNLTD7X1Q445MiiIfCkns4lKuqu7DoGcLoPR6p2xZMozf2/CeWT7GJgXs=';


export function demoLicense(): string {
  return Capacitor.getPlatform() === 'ios' ? IOS_LICENSE : ANDROID_LICENSE;
}
