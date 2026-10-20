import { CapacitorConfig } from '@capacitor/cli';


const config: CapacitorConfig = {
  appId: 'com.identixia.faceliveness',
  appName: 'Identixia Face Liveness',
  webDir: 'dist',
  backgroundColor: '#00000000',
  server: {
    androidScheme: 'https',
  },
  plugins: {
    Camera: {
      permissions: ['camera', 'photos'],
    },
  },
};


export default config;
