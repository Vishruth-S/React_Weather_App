import React from 'react';
import './WeatherDisplay.css'; // Assuming you have a CSS file for styling

const WeatherDisplay = (props) => {
  // Destructure data from props
  const {
    location,
    day,
    time,
    weatherMain,
    temp,
    humidity,
    high,
    low,
    windSpeed,
    cloud,
    icon,
    background,
    isFlipped, // New prop to control the flip state
    onFlipClick, // New prop for button click handler
    forecastData // New prop to pass forecast data
  } = props.data;

  // Dynamically set background image based on weather conditions
  const weatherMainStyle = {
    backgroundImage: `url(${process.env.PUBLIC_URL}/Assets/imgs/${background}.jpg)`,
    backgroundSize: 'cover',
    backgroundPosition: 'center',
    display: props.display,
  };

  // Render the forecast details (you'll need to style this more)
  const renderForecast = () => {
    if (!forecastData || forecastData.length === 0) {
      return <p>No forecast data available.</p>;
    }
    return (
      <div className="forecast-details">
        <h3>3-Day Forecast</h3>
        {forecastData.map((dayForecast, index) => (
          <div key={index} className="forecast-day">
            <h4>{dayForecast.date}</h4>
            <img src={dayForecast.day.condition.icon} alt="weather icon" />
            <p>{dayForecast.day.condition.text}</p>
            <p>High: {Math.round(parseInt(dayForecast.day.maxtemp_c))}&#xB0;</p>
            <p>Low: {Math.round(parseInt(dayForecast.day.mintemp_c))}&#xB0;</p>
          </div>
        ))}
      </div>
    );
  };

  return (
    <div className={`weather-main ${isFlipped ? 'is-flipped' : ''}`} style={weatherMainStyle}>
      <div className="weather-card-inner">
        <div className="weather-card-front">
          {props.data.temp ? (
            <React.Fragment>
              <div className="weather-info">
                <h1>{location}</h1>
                <h4>{day}</h4>
                <h4>{time}</h4>
              </div>
              <div className="weather-img">
                <img src={icon} alt="weather icon" />
              </div>
              <div className="weather-main-text">
                <h3>{weatherMain}</h3>
                <h2>{temp}</h2>
              </div>
              <div className="weather-details-section">
                <div className="detail-item">
                  <p>💧 {humidity}%</p>
                </div>
                <div className="detail-item">
                  <p>☁️ {cloud}%</p>
                </div>
                <div className="detail-item">
                  <p>💨 {windSpeed}km/h</p>
                </div>
              </div>
              <div className="temp-high-low">
                <p>{high} / {low}</p>
              </div>
            </React.Fragment>
          ) : null}
          <button onClick={onFlipClick} className="forecast-button">Show Forecast</button>
        </div>
        <div className="weather-card-back">
          {renderForecast()}
          <button onClick={onFlipClick} className="forecast-button">Show Current</button>
        </div>
      </div>
    </div>
  );
};

export default WeatherDisplay;