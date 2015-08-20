var serialPort = require("serialport"),
	Q = require("q");


// function to execute when button is pressed
function callback(data) {
  data = data.replace("\r", "");
  switch(data) {
    case "btn_0":
      console.log("Deploy to environment 1");
      break;
    case "btn_1":
      console.log("Deploy to environment 2");
      break;
    default: 
      console.log("Unknow button ", data);
  }
}


// Check arguments numbers
if(process.argv.length != 3 ) {
  console.log('Not enought arguments. Add path to serialport');
	console.log('Available serialport : ');
	listSerialPort().then(function() {
		process.exit(1);
	});
}

var serialPortPath = process.argv[2];

function listSerialPort() {
  var defer = Q.defer();

	serialPort.list(function (err, ports) {
	  ports.forEach(function(port) {
	    console.log('Port : ' + port.comName);
	  });
	  defer.resolve();
	});	

	return defer.promise;
}

(function run () {
	var Serialport = new serialPort.SerialPort(serialPortPath, {
		baudrate: 9600,
		parser: serialPort.parsers.readline("\n")
	});

	Serialport.on('open', function(){
		console.log('Serial Port Opened');
		Serialport.on('data', function(data) {
			callback(data);
		});
	});
})();

