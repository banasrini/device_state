import sys
import json
from Pubnub import Pubnub

publish_key = 'demo'
subscribe_key ='demo'


## -----------------------------------------------------------------------
## Initiate Pubnub State
## -----------------------------------------------------------------------
pubnub = Pubnub(publish_key=publish_key, subscribe_key=subscribe_key)
channel = 'statekeeper'
message = json.dumps({'alive': 'true', 'Temparature': 7})


# Synchronous usage
print pubnub.publish(channel, message)

