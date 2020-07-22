import React from 'react'

import './Error.css'
import 'bootstrap/dist/css/bootstrap.min.css';

const Error = (props) => {
    // console.log(props.errdisplay)
    return (
        <div style={{display: props.errdisplay}} className="errordiv">
            <p><i className="fa fa-search-minus mr-2"></i>{props.message}</p>
        </div>
    )
}

export default Error
