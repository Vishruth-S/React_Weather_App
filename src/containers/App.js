import React from 'react'
import { usePromiseTracker } from "react-promise-tracker";
import Loader from 'react-loader-spinner';

import './App.css'
import Weather from './Weather/Weather'
import Navbar from '../containers/UI/Navbar'
import Footer from './UI/Footer'

const LoadingIndicator = props => {
  const { promiseInProgress } = usePromiseTracker();
  return (
      promiseInProgress && 
      <Loader
         type="Rings"
         color="#71b62b"
         height={100}
         width={100}
         timeout={3000} //3 secs
         className="Loading-icon"
      />
  );  
}


const App = () => {
  return (
      <div className="main">
        <Navbar />
        <Weather/>
        <LoadingIndicator/>
        <Footer />
      </div>
  )
}

export default App
