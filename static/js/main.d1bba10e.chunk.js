(this.webpackJsonpapp1=this.webpackJsonpapp1||[]).push([[0],{29:function(e,a,t){e.exports=t(95)},34:function(e,a,t){},59:function(e,a,t){},77:function(e,a,t){},79:function(e,a,t){},82:function(e,a,t){var n={"./cloudDay.svg":83,"./cloudNight.svg":84,"./fog.svg":85,"./moon.svg":86,"./rainDay.svg":87,"./rainNight.svg":88,"./snow.svg":89,"./sun.svg":90};function r(e){var a=c(e);return t(a)}function c(e){if(!t.o(n,e)){var a=new Error("Cannot find module '"+e+"'");throw a.code="MODULE_NOT_FOUND",a}return n[e]}r.keys=function(){return Object.keys(n)},r.resolve=c,e.exports=r,r.id=82},83:function(e,a,t){e.exports=t.p+"static/media/cloudDay.eb5ccd91.svg"},84:function(e,a,t){e.exports=t.p+"static/media/cloudNight.bfb351b2.svg"},85:function(e,a,t){e.exports=t.p+"static/media/fog.66927525.svg"},86:function(e,a,t){e.exports=t.p+"static/media/moon.644849c6.svg"},87:function(e,a,t){e.exports=t.p+"static/media/rainDay.6b26f41e.svg"},88:function(e,a,t){e.exports=t.p+"static/media/rainNight.447a97d2.svg"},89:function(e,a,t){e.exports=t.p+"static/media/snow.06848045.svg"},90:function(e,a,t){e.exports=t.p+"static/media/sun.255a951b.svg"},91:function(e,a,t){},92:function(e,a,t){},93:function(e,a,t){},94:function(e,a,t){},95:function(e,a,t){"use strict";t.r(a);var n=t(0),r=t.n(n),c=t(20),s=t.n(c),i=(t(34),t(3)),l=t(21),o=t.n(l),m=(t(59),t(22)),u=t(23),d=t(28),p=t(27),h=t(24),g=t.n(h),f=(t(77),t(78),function(e){return r.a.createElement("div",null,r.a.createElement("form",{autoComplete:"false",onSubmit:e.submitHandler,className:"form-inline search-bar"},r.a.createElement("input",{onChange:e.inputChangeHandler,autoComplete:"off",className:"search-input",type:"search",placeholder:"Enter a location","aria-label":"Search",required:!0}),r.a.createElement("button",{className:"search-btn",type:"submit"},r.a.createElement("i",{className:"fa fa-search"}))))}),v=(t(79),t(5),t(25)),b=t(26),y=function(e){var a="none";return a="block"!==e.errdisplay&&e.data.temp?"block":"none",r.a.createElement("div",{className:e.data.background+" weather-main",style:{display:a}},r.a.createElement("div",{className:"location"},e.data.location),r.a.createElement("div",{className:"day"},e.data.day),r.a.createElement("div",{className:"time"},e.data.time),r.a.createElement("div",{className:"container descWrap"},r.a.createElement("div",{className:"desc"},r.a.createElement("div",null,e.data.background?r.a.createElement("img",{src:t(82)("./".concat(e.data.background,".svg")),alt:" ",className:"filter-white svgs"}):null,r.a.createElement("div",{className:"weatherText"},e.data.weatherMain))),r.a.createElement("div",{className:"tempMainCol"},e.data.temp,r.a.createElement("span",{className:"celsiusMain"},"C")),r.a.createElement("div",{className:"tempSubCol"},r.a.createElement("div",null,e.data.high,r.a.createElement("span",{className:"celsius"},"C"),r.a.createElement("span",null," / "),e.data.low,r.a.createElement("span",{className:"celsius"},"C")))),r.a.createElement("div",{className:"row items"},r.a.createElement("div",{className:"col-4"},r.a.createElement("i",{className:"fa fa-tint"}),r.a.createElement("span",null," ",e.data.humidity,"%")),r.a.createElement("div",{className:"col-4"},r.a.createElement("i",{className:"fa fa-cloud"}),r.a.createElement("span",null," ",e.data.cloud,"%")),r.a.createElement("div",{className:"col-4"},r.a.createElement(v.a,{icon:b.a}),r.a.createElement("span",null," ",e.data.windSpeed,"km/h"))))},E=(t(91),function(e){return r.a.createElement("div",{style:{display:e.errdisplay},className:"errordiv"},r.a.createElement("p",null,r.a.createElement("i",{className:"fa fa-search-minus mr-2"}),e.message))}),N=(t(92),function(e){Object(d.a)(t,e);var a=Object(p.a)(t);function t(){var e;Object(m.a)(this,t);for(var n=arguments.length,r=new Array(n),c=0;c<n;c++)r[c]=arguments[c];return(e=a.call.apply(a,[this].concat(r))).state={search:"",time:"",day:"",location:null,weatherMain:null,temp:!1,humidity:null,high:null,low:null,windSpeed:null,cloud:null,errmessage:!1,icon:"",background:""},e.inputChangeHandler=function(a){e.setState({search:a.target.value})},e.submitHandler=function(a){a.preventDefault();Object(i.trackPromise)(g.a.get("http://api.weatherapi.com/v1/forecast.json?key=d0c1e9b30aef451789b152051200907&q="+e.state.search+"&days=3").then((function(a){var t,n=a.data.current.condition.text,r=Math.round(parseInt(a.data.current.temp_c))+"\xb0",c=a.data.location.name,s=a.data.current.humidity,i=Math.round(parseInt(a.data.forecast.forecastday[0].day.maxtemp_c))+"\xb0",l=Math.round(parseInt(a.data.forecast.forecastday[0].day.mintemp_c))+"\xb0",o=a.data.current.cloud,m=Math.round(parseInt(a.data.current.gust_kph)),u=a.data.current.condition.icon,d=a.data.location.localtime,p=d.slice(0,10),h=d.slice(11,16),g=(":"===(t=h)[1]&&(t="0"+t),t),f=function(e){var a=e,t=+a.substr(0,2),n=t%12||12,r=t<12?" AM":" PM";return a=(n=n<10?"0"+n:n)+a.substr(2,3)+r}(g),v=function(e){var a=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"][new Date(e).getDay()],t=["January","February","March","April","May","June","July","August","September","October","November","December"][new Date(e).getMonth()];return a+","+e.slice(8,10)+" "+t}(p),b=function(e,a){var t=a[0]+a[1],n=(t=parseInt(t))>=6&&t<=19?"day":"night",r=parseInt(e);if(1e3===r)return"day"===n?"sun":"moon";if(1003===r||1006===r||1009===r)return"day"===n?"cloudDay":"cloudNight";if(1030===r||1135===r||1147===r)return"fog";return[1063,1176,1087,1276,1201,1150,1240,1273,1186,1189,1153,1168,1171,1180,1183,1185,1243,1195].includes(r)?"day"===n?"rainDay":"rainNight":"snow"}(a.data.current.condition.code,g);e.setState({errmessage:!1,weatherMain:n,temp:r,location:c,humidity:s,icon:u,high:i,low:l,windSpeed:m,cloud:o,time:f,day:v,background:b})})).catch((function(a){console.log(a.response.data);var t=a.response.data.error.message;e.setState({errmessage:t,temp:!1})})))},e}return Object(u.a)(t,[{key:"render",value:function(){var e=this.state.errmessage?"none":"block",a=this.state.errmessage?"block":"none";return r.a.createElement("div",null,r.a.createElement(f,{inputChangeHandler:this.inputChangeHandler,submitHandler:this.submitHandler}),r.a.createElement(y,{display:e,data:this.state,errdisplay:a}),r.a.createElement(E,{errdisplay:a,message:this.state.errmessage}))}}]),t}(n.Component)),w=(t(93),function(){return r.a.createElement("nav",{className:"navbar navbar-light bg-light mb-3"},r.a.createElement("span",{className:"navbar-brand mb-0 h1"},r.a.createElement("a",{href:"https://www.weatherapi.com/",title:"Free Weather API"},r.a.createElement("img",{src:"//cdn.weatherapi.com/v4/images/weatherapi_logo.png",alt:"Weather data by WeatherAPI.com",border:"0",className:"logo"}))))}),k=(t(94),function(){return r.a.createElement("div",{className:"footer"},r.a.createElement("p",{className:"footer-text"},"Designed and Developed by ",r.a.createElement("a",{href:"https://vishruth-s.github.io/Me/"},"VS")))}),M=function(e){return Object(i.usePromiseTracker)().promiseInProgress&&r.a.createElement(o.a,{type:"Rings",color:"#71b62b",height:100,width:100,timeout:3e3,className:"Loading-icon"})},D=function(){return r.a.createElement("div",{className:"main"},r.a.createElement(w,null),r.a.createElement(N,null),r.a.createElement(M,null),r.a.createElement(k,null))};Boolean("localhost"===window.location.hostname||"[::1]"===window.location.hostname||window.location.hostname.match(/^127(?:\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){3}$/));s.a.render(r.a.createElement(r.a.StrictMode,null,r.a.createElement(D,null)),document.getElementById("root")),"serviceWorker"in navigator&&navigator.serviceWorker.ready.then((function(e){e.unregister()})).catch((function(e){console.error(e.message)}))}},[[29,1,2]]]);
//# sourceMappingURL=main.d1bba10e.chunk.js.map