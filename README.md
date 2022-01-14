DI JANG YF-S402B Hall Effect Water Flow Sensor

採用霍爾感應元件來計算流量，是非常普及的方式，網路上找得到的程式範本是採用attachInterrupt的方式來計算
如果您的專案很複雜，同時要執行時間有關的函數 millis(), micro(), 與 delay()，必須自行撰寫時間延遲函數
此外Serial.print會遺失資料，UART也會不穩定

附上的程式碼是改用digitalRead來讀取流量計，只要您的mcu夠快，例如ESP32，可以非常輕鬆的讀取流量計，甚至多個流量計
目前只有量測YF-S402B每秒的脈波數，實際的每秒流量，還需要實驗才會得知
等我完成實驗後，會再更新此程式
