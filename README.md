# OTP-using-GSM  --> Generatung OTP for high security system
# components used:
     AT89C51 microcontroller
     SIM900D GSM module
     20x4 alpha numeric LCD display
     3x4 matrix keypad
# Interfacing:
     AT89C51 ---UART---> SIM900D
        ,,   ---cable---> LCD & keypad
# In main:
     step 1 -> Initialize the UART and LCD in AT89C51
     step 2 -> get mobile number from user using matrix keypad
     step 3 -> pass that mobile number to further process ie,OTP generation
     step 4 -> create random number for OTP using 'rand' function
     step 5 -> use 'AT' commands to send SMS
     step 6 -> after sending SMS ,wait for user to re-enter the OTP
     step 7 -> verify the OTP with generated random number
     step 8 -> if OTP match then open the lock
     
