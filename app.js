var serialPort = require("serialport");
var Serialport = new serialPort.SerialPort("/dev/cu.usbserial-A9691NZV", {
	baudrate: 9600,
	parser: serialPort.parsers.readline("\n")
});

Serialport.on('open', function(){
	console.log('Serial Port Opened');
	Serialport.on('data', function(data){
		console.log(data);
	});
});