import React from 'react'
import 'bootstrap/dist/css/bootstrap.min.css';
import './Navbar.css'

const Navbar = () => {
    return (
        <nav className="navbar navbar-light bg-light mb-3">
            <span className="navbar-brand mb-0 h1"><a href="https://www.weatherapi.com/" title="Free Weather API"><img src='//cdn.weatherapi.com/v4/images/weatherapi_logo.png' alt="Weather data by WeatherAPI.com" border="0" className="logo" /></a></span>
        </nav>
    )
}

export default Navbar
