---
layout: default
title: Lab
---

## Labs

1. Browse to your JDK's installation location, also known as _JAVA\_HOME_.  On MacOS, it's usually _/Library/Java/JavaVirtualMachines/jdk1.**M**.**N**\_**P**.jdk/Contents/Home/_, where M, N, and P are the major, minor, and patch version numbers of your installed JDK.

   Browse to the _jre/bin/_ subfolder and look at the binaries (executables) there.

   Browse to the _jre/lib/_ subfolder and look at the `.jar` files there.

   Compare the _bin/_ subfolder directly under JAVA\_HOME to _jre/bin/_.

2. In Eclipse open the **JVM** project.  Expand _JRE System Library_ and compare the list of `.jar` files with what's listed in _JAVA\_HOME/jre/lib/_.

   Under _JRE System Library_ expand `rt.jar`.  Find the `java.lang` package.  Do you see any familiar classes?

<hr>

[Prev](javaSpec.md) -- [Up](README.md)

