import { useHistory } from 'react-router-dom';
import { useSdk } from '../SdkContext';
import './Home.css';

/** Android FaceLivenessDetection Home: wide Liveness + Settings/About. */
export default function Home() {
  const history = useHistory();
  const sdk = useSdk();
  const ready = sdk.ready;

  const openLiveness = () => {
    if (!ready) return;
    history.push('/mode/LIVENESS');
  };

  return (
    <div className="home-root">
      <div className="home-chips">
        <div className="home-chip grow">
          {sdk.licenseLabel
            ? `License · ${sdk.licenseLabel}`
            : sdk.loading
              ? 'Starting…'
              : 'Failed'}
        </div>
        <div className="home-chip bold">
          {ready ? 'Ready' : sdk.loading ? 'Loading…' : 'Failed'}
        </div>
      </div>

      <button
        type="button"
        className="home-primary"
        disabled={!ready}
        onClick={openLiveness}
      >
        <span className="home-primary-title">LIVENESS</span>
      </button>

      <div className="home-row">
        <button type="button" className="home-small" onClick={() => history.push('/settings')}>
          SETTINGS
        </button>
        <button type="button" className="home-small" onClick={() => history.push('/about')}>
          ABOUT
        </button>
      </div>
    </div>
  );
}
