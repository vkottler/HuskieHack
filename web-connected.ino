// -----------------------------------
//Jordan Rego/ Kristen Arms
// -----------------------------------

// First, let's create our "shorthand" for the pins
// Same as in the Blink an LED example:
// led1 is D0, led2 is D7

int led1 = D2;  //yellow
int led2 = D1;  //red
int led3 = D0;   //blue

//set up our movement variables
int x = 0;
int y = 0;
int pattern = 0;


//initial intensity
int intensity = 0;

// Last time, we only needed to declare pins in the setup function.
// This time, we are also going to register our Spark function

void setup()
{

   // Here's the pin configuration, same as last time
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);

   // We are also device-ID-goes-heregoing to declare a Spark.function so that we can turn the LED on and off from the cloud.
   Particle.function("led",ledToggle);
   Particle.function("move",moveToggle);
   
   //serial shit begins here
   Serial.begin(9600);
   

}


// Last time, we wanted to continously blink the LED on and off
// Since we're waiting for input through the cloud this time,
// we don't actually need to put anything in the loop

void loop()
{
    if(pattern == 0)
    {
        analogWrite(led1, intensity);
        analogWrite(led2, intensity);
        analogWrite(led3, intensity);
        delay(50);
    }
    else if(pattern == 1)
    {
        analogWrite(led1, intensity);
        analogWrite(led2, intensity);
        analogWrite(led3, intensity);
        delay(10);
        analogWrite(led1, 200);
        analogWrite(led2, 200);
        analogWrite(led3, 200);
        delay(10);
    }
    else if(pattern == 2)
    {
        analogWrite(led1, intensity);
        analogWrite(led2, intensity);
        analogWrite(led3, intensity);
        delay(5);
        analogWrite(led1, 0);
        analogWrite(led2, 0);
        analogWrite(led3, 0);
        delay(5);
        
    }
     else if(pattern == 3)
    {
        analogWrite(led1, intensity);
        analogWrite(led2, intensity);
        analogWrite(led3, intensity);
    }
    else if(pattern == 3)
    {
        analogWrite(led1, intensity);
        analogWrite(led2, intensity);
        analogWrite(led3, intensity);
    }
   delay(50);
}

// We're going to have a super cool function now that gets called when a matching API request is sent
// This is the ledToggle function we registered to the "led" Spark.function earlier.
int moveToggle(String command) {
    if (command == "forward" )
    {
        //this is our case to move forward
        Serial.println("forward");
        return 1;
    }
    else if(command == "backward")
    {
        Serial.println("backward");
        return 2;
    }
    else if(command == "left" )
    {
        Serial.println("left");
        return 1;
    }
    else if(command == "right")
    {
        Serial.println("right");
        
        return 2;
    }
    else if(command == "stop")
    {
        Serial.println("stop");
        return 1;
    }
    else
    {
        return -1;
    }
    
    
}

int ledToggle(String command) {
    /* Spark.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */
    

    if (command=="on") 
    {
        intensity = 50;
        return 1;
    }
    else if (command=="off")
    {
        intensity = 0;
        return 0;
    }
    else if(command=="intensityUp")
    {
        intensity += 10;
        return 2;
    }
    else if(command == "pattern")
    {
        if(pattern == 4)
            {
                //arbitrary choice of 4 pattersn
                pattern = 0;
            }
        else
            {
                pattern ++;
            }
        return 1;
    }
    else if(command=="intensityDown")
    {
        if(intensity >= 10)
            {
                intensity -= 10;
                return 1;
            }
        else
        {
            return 9;
        }
    }
    else {
        return -1;
    }
}
