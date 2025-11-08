---
layout: default
title: Merging and Resolving Conflicts
---

### Merging and Resolving Conflicts

## What is Merging?

Merging is the process of integrating changes from one branch into another. When you merge, Git combines the commit histories of two branches, creating a unified version that includes changes from both.

Common scenarios for merging:
- Integrating a feature branch back into the main branch
- Updating your feature branch with the latest changes from main
- Combining work from multiple team members

## Types of Merges

### Fast-Forward Merge

A fast-forward merge occurs when there's a direct linear path from the current branch to the target branch. No new commit is created; Git simply moves the branch pointer forward.

**Scenario:** You create a feature branch, make commits, and no one has modified the main branch.

```
Before merge:
main:    A---B
              \
feature:       C---D

After fast-forward merge:
main:    A---B---C---D
```

**Command:**
```bash
git checkout main
git merge feature
```

Output: `Fast-forward`

### Three-Way Merge

A three-way merge happens when both branches have diverged with separate commits. Git creates a new "merge commit" that has two parents, preserving both histories.

**Scenario:** You're working on a feature branch while others have committed to main.

```
Before merge:
         C---D  (feature)
        /
main:  A---B---E---F

After three-way merge:
         C---D
        /     \
main:  A---B---E---F---M  (merge commit)
```

**Command:**
```bash
git checkout main
git merge feature
```

Git will create commit M, which combines changes from both branches.

## Performing Merges

### Basic Merge Workflow

1. **Ensure you're on the target branch:**
```bash
git checkout main
```

2. **Update your local branch (if working with remotes):**
```bash
git pull origin main
```

3. **Merge the feature branch:**
```bash
git merge feature-branch
```

4. **If successful, push the changes:**
```bash
git push origin main
```

### Merge Options

**Create a merge commit even for fast-forward:**
```bash
git merge --no-ff feature-branch
```
This preserves the branch history, making it clear that a feature was developed separately.

**Squash commits before merging:**
```bash
git merge --squash feature-branch
git commit -m "Add feature X"
```
This combines all feature branch commits into a single commit on the target branch.

## Understanding Merge Conflicts

### Why Conflicts Happen

A merge conflict occurs when Git cannot automatically reconcile differences between two commits. This typically happens when:

- The same lines in the same file are modified differently in both branches
- A file is modified in one branch and deleted in another
- The same file is added with different content in both branches
- Binary files are changed in both branches

Git can automatically merge changes that affect different parts of a file, but when the same lines are modified, human intervention is required.

### Conflict Markers in Files

When a conflict occurs, Git marks the conflicting sections in your files with special markers:

```
<<<<<<< HEAD
This is the content from your current branch (the branch you're merging into)
=======
This is the content from the branch you're merging in
>>>>>>> feature-branch
```

**Breakdown of markers:**
- `<<<<<<< HEAD`: Beginning of your current branch's version
- `=======`: Separator between the two versions
- `>>>>>>> branch-name`: End of the incoming branch's version

**Example conflict in code:**

```python
def calculate_total(items):
<<<<<<< HEAD
    # Calculate total with tax
    subtotal = sum(item.price for item in items)
    return subtotal * 1.08
=======
    # Calculate total with discount
    subtotal = sum(item.price for item in items)
    return subtotal * 0.9
>>>>>>> feature-discount
```

## Resolving Conflicts

### Step-by-Step Manual Resolution

1. **Identify conflicted files:**
```bash
git status
```
Look for files marked as "both modified" or "Unmerged paths".

2. **Open the conflicted file** in your text editor

3. **Choose the correct version:**
   - Keep the current branch's version (delete the other)
   - Keep the incoming branch's version (delete the other)
   - Keep both versions
   - Manually combine both changes
   - Write entirely new code

4. **Remove all conflict markers** (`<<<<<<<`, `=======`, `>>>>>>>`)

5. **Test your changes** to ensure they work correctly

6. **Stage the resolved file:**
```bash
git add filename
```

7. **Continue the merge:**
```bash
git commit
```
Git will provide a default merge commit message.

### Manual Resolution Example

**Original conflict:**
```javascript
function greet(name) {
<<<<<<< HEAD
    return `Hello, ${name}!`;
=======
    return `Hi there, ${name}!`;
>>>>>>> feature-greeting
}
```

**Resolved version (choosing to keep both as options):**
```javascript
function greet(name, formal = true) {
    return formal ? `Hello, ${name}!` : `Hi there, ${name}!`;
}
```

Then:
```bash
git add greet.js
git commit -m "Merge feature-greeting with formal parameter option"
```

### Using Merge Tools

Git supports various visual merge tools to help resolve conflicts more easily.

**Configure a merge tool:**
```bash
git config --global merge.tool vimdiff
# or
git config --global merge.tool meld
# or
git config --global merge.tool kdiff3
```

**Launch the merge tool:**
```bash
git mergetool
```

Popular merge tools:
- **VS Code**: Built-in merge conflict resolver
- **meld**: Visual diff and merge tool
- **kdiff3**: Three-way merge tool
- **P4Merge**: Free visual merge tool from Perforce
- **Beyond Compare**: Commercial tool with advanced features

**Using VS Code:**
When you open a file with conflicts in VS Code, you'll see options:
- Accept Current Change
- Accept Incoming Change
- Accept Both Changes
- Compare Changes

### Checking Conflict Status

**See which files have conflicts:**
```bash
git status
```

**See the differences:**
```bash
git diff
```

**See conflicts in a specific file:**
```bash
git diff --conflict=diff3 filename
```
This shows the base version, making it easier to understand what changed.

## Completing a Merge After Conflict Resolution

Once all conflicts are resolved:

1. **Verify all conflicts are resolved:**
```bash
git status
```
Ensure no files are listed under "Unmerged paths".

2. **Review your changes:**
```bash
git diff --staged
```

3. **Commit the merge:**
```bash
git commit
```
Git opens your editor with a default merge message. You can modify it or accept it.

4. **Alternatively, commit with a custom message:**
```bash
git commit -m "Merge feature-branch: resolved conflicts in payment module"
```

## Aborting Merges

If you want to cancel a merge and return to the state before you started:

**Abort the merge:**
```bash
git merge --abort
```

This is safe to use even if you've partially resolved conflicts. It restores your working directory to the state before the merge began.

**When to abort:**
- You realize you're merging the wrong branch
- Conflicts are too complex to resolve immediately
- You need to coordinate with team members before proceeding
- Tests reveal that the merge introduces breaking changes

## Merge Strategies

Git supports different merge strategies for various scenarios:

### Recursive (Default)

```bash
git merge -s recursive feature-branch
```
The default strategy for two branches. Handles most cases well.

**Options:**
```bash
git merge -s recursive -X ours feature-branch   # Favor current branch
git merge -s recursive -X theirs feature-branch # Favor incoming branch
```

### Ours

```bash
git merge -s ours old-feature
```
Always keeps the current branch's version, ignoring changes from the other branch. Useful for recording that a branch was merged without actually using its changes.

### Octopus

```bash
git merge branch1 branch2 branch3
```
Merges more than two branches simultaneously. Used by `git pull` when pulling multiple branches. Refuses to merge if manual conflict resolution is needed.

### Strategy Options

**Ignore whitespace changes:**
```bash
git merge -Xignore-space-change feature-branch
```

**Rename detection:**
```bash
git merge -Xrename-threshold=50 feature-branch
```

## Best Practices for Avoiding Conflicts

### 1. Merge or Rebase Frequently

Keep your feature branch updated with the main branch:
```bash
git checkout feature-branch
git merge main
# or
git rebase main
```

Frequent integration reduces the size of conflicts when they occur.

### 2. Make Small, Focused Commits

Smaller commits are easier to understand and resolve if conflicts arise. Each commit should represent a logical change.

### 3. Communicate with Your Team

- Coordinate who works on which files
- Discuss architectural changes before implementing
- Use code reviews to identify potential conflicts early

### 4. Use Feature Branches

Keep different features isolated in separate branches:
```bash
git checkout -b feature/user-authentication
git checkout -b feature/payment-processing
```

### 5. Pull Before You Push

Always update your local branch before pushing:
```bash
git pull origin main
# resolve any conflicts
git push origin main
```

### 6. Organize Code Logically

Structure your code to minimize overlap:
- Modularize functionality
- Use dependency injection
- Keep files focused on single responsibilities

### 7. Establish Team Conventions

- Code formatting standards (use linters/formatters)
- File organization patterns
- Naming conventions
- Import/include ordering

### 8. Use .gitattributes for Merge Strategies

Specify merge strategies for specific file types:
```
# .gitattributes
*.json merge=union
package-lock.json merge=ours
```

### 9. Review Before Merging

Use pull requests or merge requests to:
- Review changes before they're merged
- Run automated tests
- Get team feedback
- Catch potential conflicts early

### 10. Keep Branches Short-Lived

Long-lived branches accumulate more divergence and conflicts. Aim to merge feature branches within days or weeks, not months.

## Common Conflict Scenarios

### Scenario 1: Configuration File Conflict

**Conflict:**
```json
<<<<<<< HEAD
{
  "version": "1.2.0",
  "port": 8080
=======
{
  "version": "1.1.0",
  "port": 3000
>>>>>>> feature-api
}
```

**Resolution:**
```json
{
  "version": "1.2.0",
  "port": 3000
}
```
Keep the newer version number but the correct port for the feature.

### Scenario 2: Import Statements

**Conflict:**
```python
<<<<<<< HEAD
import os
import sys
from datetime import datetime
=======
import os
from datetime import datetime, timedelta
import requests
>>>>>>> feature-scheduler
```

**Resolution:**
```python
import os
import sys
from datetime import datetime, timedelta
import requests
```
Combine all unique imports in a logical order.

### Scenario 3: Function Modification

**Conflict:**
```javascript
function processOrder(order) {
<<<<<<< HEAD
    validateOrder(order);
    calculateTax(order);
    return saveOrder(order);
=======
    validateOrder(order);
    applyDiscount(order);
    return saveOrder(order);
>>>>>>> feature-discounts
}
```

**Resolution:**
```javascript
function processOrder(order) {
    validateOrder(order);
    applyDiscount(order);
    calculateTax(order);
    return saveOrder(order);
}
```
Include both new features in the correct logical order.

## Summary

Merging is a fundamental Git operation that integrates changes from different branches. While Git handles many merges automatically, conflicts require manual intervention. Understanding conflict markers, using appropriate tools, and following best practices helps minimize conflicts and resolve them efficiently when they occur.

**Key takeaways:**
- Fast-forward merges simply move the pointer; three-way merges create merge commits
- Conflicts occur when the same lines are modified in both branches
- Conflict markers show you both versions to help you decide
- Always test your code after resolving conflicts
- Frequent integration and good communication prevent most conflicts
- Use `git merge --abort` if you need to cancel a merge

<hr>

[Up](README.md) -- [Previous](gitBranching.md) -- [Next](gitRemotes.md)
