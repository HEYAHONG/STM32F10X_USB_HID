#ifdef WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "hidapi/hidapi.h"

#define MAX_STR 255

int main(int argc, char* argv[])
{
	int res;
	unsigned char buf[32];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;
	setbuf(stdout,NULL);
	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x483, 0x5750, NULL);

	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	wprintf(L"Manufacturer String: %s\n", wstr);

	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	wprintf(L"Product String: %s\n", wstr);

	// Read the Serial Number String
	res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	wprintf(L"Serial Number String: (%d) %s\n", wstr[0], wstr);

	// Read Indexed String 1
	res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
	wprintf(L"Indexed String 1: %s\n", wstr);

	// Toggle LED (cmd 0x80). The first byte is the report number (0x0).
	// buf[0] = 0x0;
	// buf[1] = 0x1;
	// res = hid_write(handle, buf, 2);

	// Request state (cmd 0x81). The first byte is the report number 0x0).
	// buf[0] = 0x0;
	// buf[1] = 0x1;
	// res = hid_write(handle, buf, 2);
	for(i=0;i<32;i++)
	{buf[i]=i;}
	while(1) {
	//send data
	buf[0]=0x01;
	res = hid_write(handle,buf,32);
	printf("Send %d bytes\n",res);
	// Read requested state
	res = hid_read(handle, buf,32);

	// Print out the returned buffer.
	for (i = 0; i < 32; i++)
		printf("buf[%d]: %X\n", i, buf[i]);
	}
	// Finalize the hidapi library
	res = hid_exit();

	return 0;
}
