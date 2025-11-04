---
layout: default
title: Project: Mad Lib
---


We will be creating a Mad Libs game. The game reads a story from a file, and substitutes random words into the story.

If you do not know how Mad Libs works, you can see an example here. http://www.madlibs.com/

### Project Description

#### `Map` of Words

This project contains files of words. These are in the _resources_ folder of the _MadLibsFiles_ project.

* _nouns.txt_
* _plurals.txt_
* _pronouns.txt_
* _prepositions.txt_
* _interjections.txt_
* _verbs.txt_
* _adjectives.txt_
* _adverbs.txt_
* _conjunctions.txt_

Each line is a word, and each file corresponds to a part of speech.

The placeholders in the story file will be the keys in a `Map` of words.

```
%%VERB%% -> ["run", "fight", "roundhouse kick"]
```

When the program starts, we need to open and read these files, adding each line to a collection of `String`s, placing that collection in the `Map` with the correct key.

The class `MadLibsFiles/com.example.madlibs.TextLabels` has predefined constants for the placeholders.

#### Story File
You will compose a story in a text file named _story.txt_.  Be sure to save it under _MadLibsFiles/resources/_.

Then manually replace words of your choice in the text with the following placeholders:

  * `%%NOUN%%` - person, place or thing.
  * `%%PLURAL%%` - multiple things, not just one.
  * `%%PRONOUN%%` - replace a noun. "I," "him," "he."
  * `%%PREPOSITION%%` - connect a noun to other words in a sentence. "About," "of," "to," for example.
  * `%%INTERJECTION%%` - emotion in a sentence, often followed with an exclamation point. "Jinkies!"
  * `%%VERB%%` - action word. "Hit," "run," "karate chop."
  * `%%ADJECTIVE%%` - describes a noun.
  * `%%ADVERB%%` - describes an action, usually ending in "ly." "Quickly," "throughly," etc.
  * `%%CONJUNCTION%%` - links words or phrases together. "For," "and," "so."

The program will use these placeholders for text substitution later.

* Note that you do not have to replace each part of speech in the text file with a placeholder.
* You do not even have to use all the parts of speech.
  * Start with the simple ones: nouns, verbs, adjectives.

##### Example:
```
A %%NOUN%% had a %%NOUN%% that was %%ADJECTIVE%%.
%%PREPOSITION%% %%VERB%% it %%ADVERB%% and said, "%%INTERJECTION%%!".
```
The program will then read each line of this file into a `List` of `String`s.

The placeholders in these `String`s will be replaced by actual words.

#### Text Substitution

The final step is to replace the placeholders in the text from the story file with words from the `Map`.
* Again, note that the keys in the `Map` match placeholders in the file.

Then print the new story text to the screen.

You'll need to search each line for the `%%` that begins a placeholder, and find the end of the `%%` that terminates it so you can retrieve the placeholder as a `String`.  Using the map, randomly select a word from the correct list for that placeholder and substitute it into the line.  Continue on that line until there are no more placeholders, then go to the next line of the story.

Hints:
* `String.indexOf(String str, int fromIndex)`
* `String.substring(int beginIndex, int endIndex)`
* `String.replaceFirst(String regex, String replacement)`

### Tasks

#### Task 1: Implement File I/O

The work of reading lines from a file into a `List<String>` will be handled by a `default` method in the interface `MadLibsFiles/com.example.madlibs.io.FileSource`.  Fill in the `readFileForData` method stub.

#### Task 2: Load Words Map

The class `MadLibsFiles/com.example.madlibs.io.wordsource.FileWordSource` has a `Map<String, String>` that associates a placeholder with the file containing the words for that placeholder.

In the `getWordsFromSource` method, you will use each of the keys in `tokensAndFilenames` to retrieve the filename, pass it to `readFileForData` to get the list of words from the file, and then put that list into the `Map<String, List<String>>` using the key.

#### Task 3: Story Source

Create a story source file, _story.txt_, as described above.

#### Task 4: Text Substitution

In `MadLibsFiles/com.example.madlibs.SimpleSubstitutionEngine`, implement the `doSubstitutionIndexOf` to loop through the story lines and replace each placeholder on the line with a word randomly selected from the word list for that placeholder.

### Stretch Goals
Sets of Stretch Goals are below, separated into categories.

#### Word Source

Get the words (noun, adjective, etc.) from the user instead of files.
* This is much more fun. Random words do not make for the best story.

Hints:
* A good design would use a common interface for things that change, like the two word sources (words from files and words from user interaction), or classes that do substitution.

#### User Direction
* In the file, you could give your user hints in `[]`, such as `[Capitalized noun]` or `[him, her, it]`.
* When it is time to translate the text, remove the `[]` text.
  * This type of substitution could use an expanded set of `%%xxx%%` placeholders; as long as the program's placeholders match the file, substitution will work.

* Sometimes it's better to use the same word several places in a story. Could you change the placeholders to manage this? Maybe you can use the first noun several places with the placeholder `%%NOUN-0%%`.

#### Story Input
* Let the users choose the file for the story.

* Let users enter story text, complete with placeholders.

<hr>

[Up](../README.md)
