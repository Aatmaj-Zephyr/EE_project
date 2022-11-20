## Back end - Application

##### End User- Parents/ Therepists

A) Bluetooth
  1) Bluetooth connection must be established between mobile application and the device. For this, bluetooth permission must be asked by the user every time the application starts
  2) The application must redirect to bluetooth connection page for the first pairing.
  3) For Bluetooth, appropriate error handeling must be performed in case the device is not detected or paired.
  4) If the device gets disconnected while working, appropriate handling must be performed.
  5) If the application is connected to two devices, then only one device must be chosen. _(Edge case)_

B) Starting the Game
  1) The speed of the game must be set by the user. Speed will be in terms of colors per minute. It must range from 10 to 60 in steps of 2.
  2) Once the speed is set, it can be increased or decreased during the game in steps of 2.
  3) The game duration must be set in minutes before the game starts and cannot be changed afterwards.
  4) The score must be updated and shown to the user during the course of the game, updated every 5 seconds. _(OPTIONAL)_

C) Ending the game
  1) The game must end after the specified time is over.
  2) The final score must be displayed when the game is over.
  3) The score must be compared with the previous scores of the user. (Highscore feature) _(OPTIONAL)_
  4) The progress must be shown in form of a graph _(OPTIONAL)_



