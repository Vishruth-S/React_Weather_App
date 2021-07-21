import React from 'react'
import './WeatherDisplay.css'
import 'bootstrap/dist/css/bootstrap.min.css';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faWind } from '@fortawesome/free-solid-svg-icons'

const Weather = (props) => {
    let disp = "none"
    if (props.errdisplay === "block" || !props.data.temp) {
        disp = "none"
    } else {
        disp = "block"
    }
    return (
        <div className={props.data.background + " weather-main"} style={{ display: disp }}>
            <div className="location">
                {props.data.location}
            </div>
            <div className="day">
                {props.data.day}
            </div>
            <div className="time">
                {props.data.time}
            </div>
            <div className="container descWrap">
                <div className="desc">
                    <div>
                        {/* {props.data.background ? <img src={require('../../Assets/imgs/'+props.data.background+".png")} alt=" " /> : null} */}
                        {props.data.background ? <img src={require(`../../Assets/imgs/svgs/${props.data.background}.svg`)} alt=" " className='filter-white svgs' /> : null}
                        <div className="weatherText">{props.data.weatherMain}</div>
                    </div>
                    {/* <img src = {svg} className='filter-white'/> */}
                </div>
                <div className="tempMainCol">
                    {props.data.temp}<span className="celsiusMain">C</span>
                </div>
                <div className="tempSubCol">
                    <div>
                        {/* <span>&#8593; </span> */}
                        {props.data.high}<span className="celsius">C</span>
                        {/* <span>    &#8595; </span> */}
                        <span> / </span>{props.data.low}<span className="celsius">C</span>
                    </div>
                </div>
            </div>
            <div className="row items">
                <div className="col-4">
                    <i className="fa fa-tint"></i><span> {props.data.humidity}%</span>
                </div>
                <div className="col-4">
                    <i className="fa fa-cloud"></i><span> {props.data.cloud}%</span>
                </div>
                <div className="col-4">
                    <FontAwesomeIcon icon={faWind} />
                    <span> {props.data.windSpeed}km/h</span>
                </div>
            </div>

            {/* <section>
                <div className="wave wave1"></div>
                <div className="wave wave2"></div>
                <div className="wave wave3"></div>
                <div className="wave wave4"></div>
            </section> */}
        </div>
    )
}

export default Weather
