function formToJson(form) { 
    var pass = form.pass.value; 
    var ssid = form.ssid.value; 
    var jsonFormInfo = JSON.stringify({ pass: pass, ssid: ssid }); 
    window.alert(jsonFormInfo); 
}