## Arduino Backend

#### End user - Patients/ Children

A) Bluetooth
  1) The arduino module must pair with the first available bluetooth device.
  2) After sucessfull pairing and connection LED must flash Blue
  3) If the bluetooth gets disconnected while the program is running, the LED must flash RED.
  4) The speed data sent over the bluetooth must be collected and set in the program.
  5) The score data must be sent over bluetooth at the end of the game.
  6) The score data must be sent over bluetooth during the game after every 5 seconds _(optional)_

B) Logic of the game
  1) RBG light must glow at one random color
  2) If the button corresponding to the color is pressed the correctKeyCount must increase score must increase.
  3) Time between correct key pressing and color flashing is measured in reactionTime.
  4) If any other button is pressed, incorrectKeyCount must increase, score must decrease.
  5) If no Key is pressed, skippedTurnCount must increase.
  6) RGB LED must change color after any key is pressed and released.
  7) If No key is pressed, then RGB LED must change color after timeBetweenTurns time has elapsed.
  8) If key is pressed and not released then RGB LED must change color after timeBetweenTurns time has elapsed and it will be counted as pressed again.
  9) If more than one key is pressed, then the first key is counted as the key and rest key is just ignored completely and wont be counted as pressed again.
  10) at end of totalGameTime, the game will stop.

> Score data - (correctKeyCount,reactionTime,IncorrectKeyCount,SkippedTurnCount)
> Speed data - (timeBetweenTurns, totalGameTime)
