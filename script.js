
var myLineChart;

function clicare(){
	console.log('HEllo')
	//addData(myLineChart, 'month', 78)
	MQTTconnect();
 //document.getElementById("demo").innerHTML = "Hello JavaScript!"
}


        var mqtt;
		var reconnectTimeout = 2000;
		var host="broker.mqtt-dashboard.com"; //change this
		//var host="Broker.hivemq.com"
		//var port=8000  ..18.185.204.31
		var port=8000;
		
		
		function onFailure(message) {
			console.log("Connection Attempt to Host "+host+"Failed");
			setTimeout(MQTTconnect, reconnectTimeout);
        }
		var count = 0;
		function onMessageArrived(msg){
			out_msg="Message received "+msg.payloadString+"<br>";
			out_msg=out_msg+"Message received Topic "+msg.destinationName;
			console.log(out_msg);
			document.getElementById("mqtt_message").innerHTML = msg.payloadString;
			count++;
			addData(myLineChart, count, parseInt(msg.payloadString))

		}
		
	 	function onConnect() {
	  // Once a connection has been made, make a subscription and send a message.
	
		console.log("Connected ");
		mqtt.subscribe("Scients_IoT");
		message = new Paho.MQTT.Message("Hello World");
		//message.destinationName = "sensor1";
		//mqtt.send(message);
	  }
	  function MQTTconnect() {
		console.log("connecting to "+ host +" "+ port);
		mqtt = new Paho.MQTT.Client(host,port,"clientjs_scients");
		//document.write("connecting to "+ host);
		var options = {
			timeout: 3,
			onSuccess: onConnect,
			onFailure: onFailure,
			 };
		mqtt.onMessageArrived = onMessageArrived
		
		mqtt.connect(options); //connect
		}

	window.onload = function (){var ctx = document.getElementById('myChart');

	
	myLineChart = new Chart(ctx, {
    type: 'line',
    data:{
    	labels: ['first'],
    	datasets: [{
    		label: "ESP32",
    		data:['1'],
    		borderWidth: 6,
    		borderColor:'rgba(77,166,253,0.8)',
    		backgroundColor: 'transparent'
    	}]

    }
   
});

	 myLineChart.options = {
    	responsive:true,
    	maintainAspectRatio: false
    }

}



function addData(chart, label, data) {
    //chart.data.dataset.data.shift();
    //chart.data.dataset.label.shift();
    //var dataAttribute = chart.data.datasets[0].data;

    chart.data.labels.push(label);

    //chart.data.datasets.forEach((dataset) => {
        chart.data.datasets[0].data.push(data);
        
        if(label%3 == 0){
          chart.data.datasets[0].data.shift();
          //chart.data.datasets[0].label.shift();

        }

        
    //});
    
    chart.update();
}

