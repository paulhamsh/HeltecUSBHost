# HeltecUSBHost

USB Host using generic 'DuinoFun USB Mini v2.0' from ebay and Heltec ESP 32 board   

Using information in these websites:   

https://github.com/felis/USB_Host_Shield_2.0   

https://www.hackster.io/139994/plug-any-usb-device-on-an-esp8266-e0ca8a   

You will need to install the USB Host library:   

Download from https://github.com/felis/USB_Host_Shield_2.0 as .zip   
	-> USB_Host_Shield_2.0-master.zip   
	In the Arduino GUI ->  Sketch - Include Library - Add .zip library   


Connections are:   
GPIO5 : SS   
GPIO17 : INT   
GPIO18 : SCK   
GPIO19 : MISO   
GPIO23 : MOSI   

On the USB Host board, RST is at 3v3.   
Also cut the track by the 2k2 resistor as shown - then solder on a wire to the inner connection and connect that to 5v.   
This will power the USB from the 5v line.   
Check the track is actually broken here otherwise you will short the 5v and 3v3.    

On the picture below, the white arrows show there the track is cut, where the extra wire is soldered and where that wire comes out from under the board.   


![Example](https://github.com/paulhamsh/HeltecUSBHost/blob/main/hostcloseup.jpg)

And this is a picture of the bottom of the board with the 5v wire poking through the hole from underneath.    


![Example](https://github.com/paulhamsh/HeltecUSBHost/blob/main/underside.jpg)   

![Example](https://github.com/paulhamsh/HeltecUSBHost/blob/main/circuit.jpg)


![Example](https://github.com/paulhamsh/HeltecUSBHost/blob/main/board.jpg)

