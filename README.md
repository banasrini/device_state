device_state
============

This tutorial digs into **PubNub Storage and Playback** that helps you store and retrieve the **state** of connected devices in a home. 
Typical example of a state will be a JSON object looking like this:

{"state":[
    {"alive":"true"}, 
    {"CoffeeAmount: Half"},
    {"Temperature":"45"}
]}

The procedure is simple : 

1. Create a PubNub account for "FREE", 
2. publish messages to the PubNub Cloud using the Raspberry Pi and Arduino that control your home devices, 
3. access these messages through your favorite browser.
