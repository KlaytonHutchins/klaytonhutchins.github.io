---
layout: default
title: Sorting Map
---


A `TreeMap` sorts its _keys_, using their own natural sort order.

```java
  public static void main(String[] args) {
    Map<String,USState> states = new TreeMap<>();
    states.put("CO", new USState("CO","Colorado","Denver",5_607_154));
    states.put("CA", new USState("CA","California","Sacramento",39_536_653));
    states.put("NC", new USState("NC","North Carolina","Raleigh",10_273_419));
    states.put("ND", new USState("ND","North Dakota","Bismarck",755_393));
    states.put("NY", new USState("NY","New York","Albany",19_849_399 ));
    states.put("NJ", new USState("NJ","New Jersey","Trenton", 9_005_644));
    states.put("TX", new USState("TX","Texas","Austin", 28_304_596));
    states.put("AK", new USState("AK","Alaska","Juneau",739_795));
    states.put("WY", new USState("WY","Wyoming","Cheyenne",579_315));

    printStates(states);
  }

  private static void printStates(Map<String, USState> states) {
    Set<String> keys = states.keySet();
    for (String key : keys) {
      USState state = states.get(key);
      System.out.println(key+": "+state.getName() +", population "+state.getPopulation());
    }
  }
}
```
```
AK: Alaska, population 739795
CA: California, population 39536653
CO: Colorado, population 5607154
NC: North Carolina, population 10273419
ND: North Dakota, population 755393
NJ: New Jersey, population 9005644
NY: New York, population 19849399
TX: Texas, population 28304596
WY: Wyoming, population 579315
```

To sort the keys of other `Map` implementations, or to change the sort order, we can use a `Comparator`.

* Its `compare` takes two keys, which it uses to retrieve the mapped values from the map.

* It can then use properties of the retreived value objects to determine the sort order.

For this to work, the `Comparator` must have access to the `Map` object.

```java
public class USStatePopulationComparator implements Comparator<String> {
  // Field to store a reference to a map
  private Map<String,USState> states;

  // Constructor requires a Map<String,USState> reference to put in the field
  public USStatePopulationComparator(Map<String,USState> states) {
    this.states = states;
  }

  @Override
  public int compare(String abbr1, String abbr2) {
    // compare uses keys to access objects whose properties define the order
    USState state1 = states.get(abbr1);
    USState state2 = states.get(abbr2);
    if (state1.getPopulation() > state2.getPopulation()) {
      return 1;
    }
    else if (state1.getPopulation() < state2.getPopulation()) {
      return -1;
    }
    return 0;
  }
}
```

Use the `Comparator` to sort the keys, then use the keys to retrieve the values.

```java
Set<String> abbrevs = states.keySet();
// A Set can't be sorted, but a List can
List<String> keys = new ArrayList<>(abbrevs);
// Pass map reference to the comparator's constructor
Comparator<String> comp = new USStatePopulationComparator(states);
// Sort keys with the comparator.
keys.sort(comp);

// Use the sorted keys to access the values
System.out.println("== Sorted by population ==");
for (String abbrev : keys) {
  USState state = states.get(abbrev);
  System.out.println(abbrev+": "+state.getName()+", population "+state.getPopulation());
}
```

<hr>

[Prev](SortingLists.md) -- [Up](README.md) -- [Next](ArraysClass.md)

