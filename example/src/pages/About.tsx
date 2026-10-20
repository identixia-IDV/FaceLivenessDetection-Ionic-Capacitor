import { useSdk } from '../SdkContext';
import {
  IonButton,
  IonButtons,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
} from '@ionic/react';
import { useHistory } from 'react-router-dom';
import { goHome } from '../nav';

export default function About() {
  const history = useHistory();
  const { licenseLabel } = useSdk();


  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonButton onClick={() => goHome(history)}>Back</IonButton>
          </IonButtons>
          <IonTitle>About</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <h1 className="page-title">Identixia</h1>
        <div className="product-sub">Face Recognition SDK</div>
        <div className="about-license">{`License: ${licenseLabel}`}</div>
        <div className="about-card">
          Identixia builds on-device identity technology — face recognition,
          liveness, and document reading — so biometric data never has to leave
          the phone.
        </div>
        <div className="about-card">
          This app demos the Face Recognition SDK for Ionic Capacitor: enroll,
          identify, capture, and attribute analysis. Everything runs fully
          on-premise.
        </div>
        <p className="about-link">
          <a href="https://identixia.com" target="_blank" rel="noreferrer">
            identixia.com
          </a>
        </p>
        <p className="muted" style={{ textAlign: 'center' }}>
          © 2026 Identixia. All rights reserved.
        </p>
      </IonContent>
    </IonPage>
  );
}
