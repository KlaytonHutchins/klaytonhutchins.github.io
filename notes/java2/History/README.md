---
layout: default
title: History
---

## History

[Starter Code: `History/com.example.history`:](resources/History.zip)

* Check your _java2_ working set in Eclipse. If the `History` project is not found, import this _zip_ into your _Projects_ working set.

This project defines a `President` class modeling historical data about a US President.

There is an `interface PresidentMatcher` with a single `abstract` method `matches(President pres, String string)` returning a `boolean`.

The implementation `class PresidentPartyMatcher`'s `matches` returns true if the president's party equals the string argument, ignoring case.

`PresidentApp` reads _presidents.tsv_, which contains tab-separated records.  It parses each record and uses the fields to create a `President` object which it adds to a `List<President>`.

Run this stubbed application to make sure all files are in place.  Review all of the code and make sure you understand how this starter application works.

*  [Working with Dates and Times](datesTimes.md) 
*  [Sorting and Filtering with Inner Classes](innerClasses.md) 
*  [Sorting and Filtering with Lambdas](lambdas.md) 

<hr>

[Up](../README.md) -- [Next](datesTimes.md)
