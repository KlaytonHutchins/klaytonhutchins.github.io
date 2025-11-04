---
layout: default
title: Install and Configure Tomcat Web Container
---


### Download and install Tomcat 8.5

* Download Tomcat 8.5 from https://tomcat.apache.org/download-80.cgi

  * Get the most recent version of Tomcat 8.5

  * You only need the Core zip file.

* Create the folder `~/SD/Tools/`, if it doesn't exist.

  ```bash
  mkdir ~/SD/Tools/
  ```

* `cd` into the folder, and move the downloaded Tomcat 8.5 zip to it:

  ```bash
  cd ~/SD/Tools/
  mv ~/Downloads/apache-tomcat-8.5.28.zip .
  ```

* Extract the zip, creating the Tomcat installation directory:

  ```bash
  unzip -q apache-tomcat-8.5.28.zip
  ```

  * That's it for Tomcat, no further setup required.

  * Leave the ZIP file there - if something goes weird later, you can just remove the tomcat folder and re-extract from the ZIP.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](eclipseServerSetup.md)

