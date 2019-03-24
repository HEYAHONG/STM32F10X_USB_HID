1.这是一个用STM32F103开发USB-HID设备的程序，所有代码均是在官方库文件的基础上修改而来。目录说明如下:
app_usb_lib:USB相关库文件，需要根据实际情况修改。
Libraries:标准库文件，一般不需要修改。
project:工程目录。
tool:工具目录。现有上位机测试程序。
2.除去删除的多余代码，现修改了以下文件。
main.c:main函数
app_usb_lib/src/usb_endp.c:EP1_OUT_Callback()函数
以上修改均是为了用测试工具进行测试，如不需要，可在相关函数中删除测试代码。

