 // Initialize with Publish & Subscribe Keys
 
 var pubnub = PUBNUB.init({
     publish_key: 'demo',
     subscribe_key: 'demo',
     uuid: 'statekeeper'
 });
 
 // Retrieving the messages that have been published on to this channel using History. 
 
 pubnub.history({
     channel: 'history_channel',
     callback: function(m){console.log(JSON.stringify(m))},
 });
