## JSTL - Map Iteration
You can also use `<c:forEach>` to iterate over Maps.

* With a Map, the `var` attribute represents a map entry - a key/value pair.

* You must use its `key` and `value` properties to access the actual data.
  ```java
  Map<Integer, Student> studentMap = new HashMap<>();
  studentMap.put(12, s1);
  studentMap.put(9, s2);

  req.setAttribute("mapStudents", studentMap);
  ```

  ```xml
  <select name="students">
    <c:forEach var="student" items="${mapStudents}">
      <option value="${student.key}">${student.value.name}</option>
    </c:forEach>
  </select>
  ```

<hr>

[Prev](list-iteration.md) | [Up](README.md) | [Next](formatting.md)

