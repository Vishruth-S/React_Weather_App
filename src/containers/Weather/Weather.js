import React, { Component } from 'react'
import axios from 'axios'
import { trackPromise } from 'react-promise-tracker';

import SearchForm from '../SearchForm/SearchForm'
import WeatherDisplay from '../WeatherDisplay/WeatherDisplay'
import Error from '../Error/Error'
import './Weather.css'



class Weather extends Component {
  state = {
    search: '',
    time: '',
    day: '',
    location: null,
    weatherMain: null,
    temp: false,
    humidity: null,
    high: null,
    low: null,
    windSpeed: null,
    cloud: null,
    errmessage: false,
    icon: '',
    background: '',
  }

  inputChangeHandler = (e) => {
    this.setState({
      search: e.target.value
    })
  }
  submitHandler = (e) => {
    e.preventDefault();  // It will hold the form submit
    // console.log('state:', this.state.search);
    const calculate_day = (date) => {
      let days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
      let d = new Date(date);
      let dayName = days[d.getDay()];
      let month_name = function (dt) {
        let mlist = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
        return mlist[dt.getMonth()];
      };
      // console.log(month_name(new Date(date)));
      let monthname = month_name(new Date(date));
      let day = dayName + "," + date.slice(8, 10) + " " + monthname;
      return day
    }
    const calculate_time = (time24) => {
      // console.log(time24)
      var ts = time24;

      // console.log(ts)
      var H = +ts.substr(0, 2);
      // console.log(H)
      var h = (H % 12) || 12;
      h = (h < 10) ? ("0" + h) : h;  // leading 0 at the left for 1 digit hours
      // console.log(h)
      var ampm = H < 12 ? " AM" : " PM";
      ts = h + ts.substr(2, 3) + ampm;
      // console.log(ts)
      return ts;
    }

    const background_calculate = (codestr, time) => {
      let str = time[0] + time[1]
      str = parseInt(str)
      // console.log(str)
      let daynight = str >= 6 && str <= 19 ? "day" : "night";
      // console.log(daynight)
      let code = parseInt(codestr)
      if (code === 1000) {
        if (daynight === "day")
          return "sun"
        else
          return "moon"
      }
      if (code === 1003 || code === 1006 || code === 1009) {
        if (daynight === "day")
          return "cloudDay"
        return "cloudNight"
      }
      if (code === 1030 || code === 1135 || code === 1147) {
        return "fog"
      }
      let arr = [1063, 1176, 1087, 1276, 1201, 1150, 1240, 1273, 1186, 1189, 1153, 1168, 1171, 1180, 1183, 1185, 1243, 1195];
      if (arr.includes(code)) {
        if (daynight === "day")
          return "rainDay"
        return "rainNight"
      }
      return "snow"
    }

    const indent_time = (ts) => {
      if (ts[1] === ":") {
        ts = "0" + ts;
      }
      return ts
    }

    trackPromise(axios.get('https://api.weatherapi.com/v1/forecast.json?key=d0c1e9b30aef451789b152051200907&q=' + this.state.search + "&days=3")
      .then(res => {
        // console.log(res);
        const weathermain = res.data.current.condition.text;
        const tempr = Math.round(parseInt(res.data.current.temp_c)) + "\xB0";
        const location = res.data.location.name;
        const humidity = res.data.current.humidity;
        const high = Math.round(parseInt(res.data.forecast.forecastday[0].day.maxtemp_c)) + "\xB0";
        const low = Math.round(parseInt(res.data.forecast.forecastday[0].day.mintemp_c)) + "\xB0";
        const cloud = res.data.current.cloud;
        const windSpeed = Math.round(parseInt(res.data.current.gust_kph));
        const icon = res.data.current.condition.icon;
        const localtime = res.data.location.localtime;
        const date = localtime.slice(0, 10);
        const time24Not = localtime.slice(11, 16);
        const time24 = indent_time(time24Not);

        const time = calculate_time(time24);
        const day = calculate_day(date);
        const code = res.data.current.condition.code;
        const background = background_calculate(code, time24);
        this.setState({
          errmessage: false,
          weatherMain: weathermain,
          temp: tempr,
          location: location,
          humidity: humidity,
          icon: icon,
          high: high,
          low: low,
          windSpeed: windSpeed,
          cloud: cloud,
          time: time,
          day: day,
          background: background,
        })
      })
      .catch(err => {
        console.log(err.response.data)
        let errormsg = err.response.data.error.message;
        // console.log(errormsg);
        this.setState({
          errmessage: errormsg,
          temp: false,
        })

      }))
  };

  render() {
    let disp = this.state.errmessage ? "none" : "block"
    let errdisp = this.state.errmessage ? "block" : "none"
    return (
      <div>
        {/* <h2>Weather</h2> */}
        <SearchForm inputChangeHandler={this.inputChangeHandler} submitHandler={this.submitHandler} />
        <WeatherDisplay display={disp} data={this.state} errdisplay={errdisp} />
        <Error errdisplay={errdisp} message={this.state.errmessage} />
      </div>
    )
  }
}

export default Weather