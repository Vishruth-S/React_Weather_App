import React from 'react'
import './SearchForm.css'
import 'font-awesome/css/font-awesome.min.css';


const SearchForm = (props) => {
    return (
        <div>
            {/* <form onSubmit={props.submitHandler}> 
                <input onChange={props.inputChangeHandler} />
                <button type='submit' >Submit</button>
            </form> */}
            {/* <form autoComplete="false" onSubmit={props.submitHandler} className="search-bar">
                <input onChange={props.inputChangeHandler} type="search" autoComplete="off" name="search" pattern=".*\S.*" placeholder="Enter a location" required />
                <button className="search-btn" type="submit">
                    <span>Search</span>
                </button>
            </form> */}
            <form autoComplete="false" onSubmit={props.submitHandler} className="form-inline search-bar">
                <input onChange={props.inputChangeHandler} autoComplete="off" className="search-input" type="search" placeholder="Enter a location" aria-label="Search" required/>
                <button className="search-btn" type="submit"><i className="fa fa-search"></i></button>
            </form>
 
        </div>
    )
}

export default SearchForm
