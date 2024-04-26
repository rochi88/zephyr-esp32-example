# Memfault Zephyr + ESP32C3 Example

This sample app is based on the Zephyr `samples/net/wifi` example. It
demonstrates a Zephyr + ESP32 integration with the Memfault SDK. It has been
tested on the following boards:

- `esp32c3_devkitm` (default board)
- `esp32s3_devkitm`

## Getting Started

The Memfault Zephyr integration guide is an excellent reference, and documents
how the Memfault SDK was added to the base example app:

https://docs.memfault.com/docs/mcu/zephyr-guide

To try out this example app:

1. Set up the Zephyr prerequisites: https://docs.zephyrproject.org/latest/develop/getting_started/index.html
2. Create a zephyr workspace and set it up with this project:

   ```bash
   $ mkdir zephyr-workspace
   $ cd zephyr-workspace
   $ west init -m https://github.com/memfault/zephyr-esp32-example
   $ west update
   ```

3. Build the example app:

   ```bash
   $ west build zephyr-esp32-example
   ```

4. Flash the example app:

   ```bash
    $ west flash
   ```

5. Open a serial console and interact with the sample app shell. For example
   using PySerial:

   ```bash
   # select the correct serial port for your system
   pyserial-miniterm --raw /dev/serial/by-id/usb-Silicon_Labs_CP2102N_USB_to_UART_Bridge_Controller_1cd857b4d5a0eb11bf35cdacdf749906-if00-port0 115200

   uart:~$ mflt get_device_info
   [00:09:21.911,000] <inf> mflt: S/N: DEMOSERIAL
   [00:09:21.911,000] <inf> mflt: SW type: zephyr-app
   [00:09:21.911,000] <inf> mflt: SW version: 0.0.1727a85c
   [00:09:21.911,000] <inf> mflt: HW version: esp32c3_devkitm

   # connect wifi
   uart:~$ wifi connect <ssid> <pw>

   # test memfault export over uart
   uart:~$ mflt export
   MC:CAKnAgIDAQpqemVwaHlyLWFwcAltMS4wLjArZDU5MmRhOAZvZXNwMzJjM19kZXZraXRtC0Z1sxH2/usEogEABQAISg==:
   ```
