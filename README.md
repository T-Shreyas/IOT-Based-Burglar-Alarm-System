# IOT-Based-Burglar-Alarm-System
IOT Based Burglar Alarm System ( NodeMCU, Magnetic Reed Switch )

## ❖ Objectives:

I. Detects Unnecessary movement within a close proximity using ultrasonic sensor and sends an SMS to the user in case the distance is less than set threshold.

II. If the Closed door Attached with Magnetic reed Switch is openedforcibly without owners’ knowledge a telegram call is made to alert the owner of the house immediately to take police action on such suspicious activity.

## ❖ Block Diagram:
| ![](Images/block.png) | 
|:--:| 
| **Figure 1 :** *Block Diagram* |

The NodeMCU collects information of Security breach from either Ultrasonic 
Sensor or the Magnetic Reed Switch and sends a SMS or Call to the User 
with the Help of IFTTT and Telegram Application alerting the user to take 
immediate effective action.

### ❖ Hardware Used:
i. NodeMCU ESP8266
ii. HC-SR04 ultrasonic sensor
iii. Magnetic Reed Switch
iv. Connecting wires and Resistors:

### ❖ Working Principle of Magnetic Reed Switch:
The simplest magnetic-field sensor is a reed switch. It contains two 
ferromagnetic nickel and iron reed elements in an evacuated, hermetically 
sealed glass tube to minimize contact arcing. The switching mechanism is 
comprised of those two ferromagnetic blades, separated by only a few 
microns. When a magnet approaches these blades, the two blades pull 
toward one another. Once touching, the blades close the normally open (NO) 
contacts, allowing electricity to flow. Some reed switches also contain a non-ferromagnetic contact, which forms a normally closed (NC) output. An 
approaching magnet will disconnect the contact and pull away from the 
switching contact.

| ![](Images/work.png) | 
|:--:| 
| **Figure 2 :** *Working Principle* |

## ❖ Methodology:
### ❖ IFTTT:
IFTTT derives its name from the programming conditional statement “if this, 
then that.” What the company provides is a software platform that connects 
apps, devices and services from different developers in order to trigger one or 
more automations involving those apps, devices and services.
### ❖ How IFTTT works?
The automations are accomplished via applets — which are sort of like 
macros that connect multiple apps to run automated tasks. We can 
turn on or off an applet using IFTTT’s website or mobile apps (and/or 
the mobile apps’ IFTTT widgets). We can also create your own 
applets or make variations of existing ones via IFTTT’s user-friendly, 
straightforward interface.
### ❖ Applets Used:
a) Webhooks: A Webhook allows you to integrate with services 
that are not already on IFTTT using simple web requests. These 
Webhooks are unique to you using your own unique URL key, 
which can be found in the Documentation section of the 
Webhooks service page. A Webhook can act as both a trigger 
and an action, so the web requests are extremely flexible and 
customizable.
b) CallMeBot Phone Call integrations: Make Free Telegram 
Phone Calls when a Trigger is fired. A Robot telegram bot will 
Call you. This service requires a Telegram App installed in your 
phone to receive calls.
c) Android SMS integrations: Android SMS is a native service 
that allows you to receive Short Message Service (SMS) 
messages on your device and send messages to other phone 
numbers. Standard carrier rates may apply. This service 
requires the IFTTT app for Android.

