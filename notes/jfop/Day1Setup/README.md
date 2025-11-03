## Day One System Setup

### Overview

First we're going to verify you have installed all the software necessary to get started programming today.

If you completed the pre-work, these should already be installed, but we're going to verify this now.

### Prerequisites
* You need to be an Admin on your machine.  

### Software

#### Slack
Slack is a team collaboration tool similar to g-chat or AIM which developer teams can use to share code snippets, and communicate with teams.
* *[https://slack.com/][slack]*
* Signup: We will send a Slack invite to your email address so you can create your Slack account and join the team
  * You will then be added to the appropriate channels.
* Download: The Mac Slack application is really convenient and easy to use (vastly superior to the browser interface), you can download it here: [https://slack.com/downloads][slackdown]  
* Slack also has an app for both Android and iPhone - we recommend you install this and get it logged in.

#### Git
Git is version control software that we will start using later this week and througout the program

* *[http://git-scm.com/download/mac][gitdown]*  
* Follow the install instructions on the link above  

#### Github
Github is a collaboration/social tool for developers which we will be using to share resources - including course material - and code throughout the program.  Github will also be a good place for you to display your work to employers down the road, so we are going to make fairly extensive use of it.  
* *[https://github.com/][gh]*
* If you don't already have a GitHub account, create one now.
  * Go to [https://github.com/][gh]
  * Pick a username - this username will identify you to anyone looking at your code or pages on the site, so choose something appropriate.
  * Enter your email, set a password, and sign up.

#### Atom
Atom is a sophisticated, open-source text editor by and for programmers.
* *[https://atom.io/][atom]*  
* Download _Atom.zip_ and open it.
* Drag _Atom app_ to the _Applications_ folder.
* Drag _Atom.app_ from _Applications_ down to the Dock bar.
* Open Atom
  * Go to the _Atom_ menu
  * Select _Install Shell Commands_ - this will allow you to run the `atom` command from the _Terminal_ command line.

### Practice Exercise
It's important that you install _Atom.app_ under _Applications_, and run it from there.  If you run it from _Downloads_ or somewhere else, the shell commands must be reinstalled any time Atom changes.

#### Chrome
Chrome is Google's free web browser.
* *[https://support.google.com/chrome/answer/95346?hl=en][chrome]*  

* Due to browser inconsistencies it will be helpful for all of us to be on the same client.
* For various reasons (dev tools and google cast included) we have chosen Google Chrome. If you do not already have Google Chrome installed, click the link above and use the Mac install instructions.  

#### Keyboard Repeat
The speed at which your keys wait to repeat can have a surprising effect on your productivity. We recommend that you reduce the time between repeat as much as possible.
* *This one is a system preference setting*  
* Open spotlight (command + spacebar), or use the Apple menu, and go to _System Preferences_.
  * Click on _Keyboard_
  * Under _Key Repeat_ move the slider to _Fast_
  * Under _Delay Until Repeat_ move the slider all the way to _Short_  

#### Terminal
You'll be doing a lot of work in the _Terminal_ command line.  When you open the Mac terminal app you're using the Bash command-line shell - the same shell as Linux.  Let's add the _Terminal_ app to the Dock for quick access.
* _Cmd_-Space to open _Spotlight_ search, then type `terminal`, and do not press Enter.
* Drag the _Terminal_ app (should be the Top Hit) down to the Dock bar.

#### Java SE Development Kit
*[http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html][jdk]*

* If you did the program pre-work then you already have this installed.  Confirm by opening a terminal window and typing:
  ```bash
  java -version
  javac -version
  ```
  * If either command fails, check with your instructor for help making sure the JSDK is properly installed.

Once we've verified these software installs, we'll  [Set Up the Initial Development Environment](CommandLine.md) .


#### Resources

 [commandline.zip](commandline.zip) 

[slack]:https://slack.com/
[slackdown]:https://slack.com/downloads
[gitdown]:http://git-scm.com/download/mac
[gh]:https://github.com/
[atom]:https://atom.io/
[chrome]:https://support.google.com/chrome/answer/95346?hl=en
[wrangler]:https://itunes.apple.com/us/app/textwrangler/id404010395?mt=12
[cast]:https://chrome.google.com/webstore/detail/google-cast-beta/dliochdbjfkdbacpmhlcpmleaejidimm?hl=en
[jdk]:http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html



<hr>

[Up](../README.md) | [Next](CommandLine.md)
