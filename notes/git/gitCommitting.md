---
layout: default
title: Staging and Committing
---

### Staging and Committing

Understanding how to stage and commit changes is fundamental to working with Git. This guide covers the complete workflow from making changes to recording them in your repository's history.

## The Three-Stage Workflow

Git uses a three-stage workflow that gives you fine-grained control over what gets committed:

1. **Working Directory**: Where you make changes to your files
2. **Staging Area (Index)**: Where you prepare changes for the next commit
3. **Repository (.git directory)**: Where commits are permanently stored

```
Working Directory  -->  Staging Area  -->  Repository
    (modify)           (git add)         (git commit)
```

This staging area is what makes Git unique. It allows you to craft precise commits by choosing exactly which changes to include, even within a single file.

## Staging Changes with git add

The `git add` command moves changes from your working directory to the staging area.

### Adding Specific Files

```bash
# Add a single file
git add README.md

# Add multiple specific files
git add index.html style.css script.js

# Add all files in a directory
git add src/

# Add all files with a specific extension
git add *.js
```

### Adding All Changes

```bash
# Add all modified and new files (recommended)
git add .

# Add all changes including deletions
git add -A
# or
git add --all

# Add only modified and deleted files (not new files)
git add -u
```

### Interactive Staging

Interactive staging gives you precise control over what to stage:

```bash
# Interactive mode - choose which files to stage
git add -i

# Patch mode - stage parts of files
git add -p

# Review each change and choose y (yes), n (no), s (split), or q (quit)
git add -p index.html
```

**Example interactive session:**
```bash
$ git add -p index.html
diff --git a/index.html b/index.html
@@ -10,6 +10,7 @@
 <body>
     <h1>Welcome</h1>
+    <p>New paragraph</p>
Stage this hunk [y,n,q,a,d,s,e,?]? y
```

### Unstaging Files

If you accidentally staged something:

```bash
# Unstage a specific file
git reset HEAD README.md

# Unstage all files
git reset HEAD

# In Git 2.23+, use restore
git restore --staged README.md
```

## Committing Changes with git commit

Once you've staged your changes, create a commit to save them to the repository.

### Basic Commit

```bash
# Opens default editor for commit message
git commit

# Commit with inline message
git commit -m "Add user authentication feature"

# Stage all modified files and commit (skips git add for tracked files)
git commit -a -m "Fix navigation bug"
# or
git commit -am "Fix navigation bug"
```

### Writing Good Commit Messages

A well-crafted commit message is crucial for project maintainability.

**Standard Format:**
```
Short summary (50 characters or less)

More detailed explanation if needed (wrap at 72 characters).
Explain the problem this commit solves and why this approach
was chosen.

- Bullet points are okay
- Use present tense: "Fix bug" not "Fixed bug"
- Reference issues: "Fixes #123"
```

**Examples:**

**Good commit messages:**
```
Add password reset functionality

Implement email-based password reset flow:
- Add reset token generation
- Create reset email template
- Add reset form and validation
- Update user model with reset fields

Fixes #456
```

```
Refactor database connection pooling

Replace custom connection manager with HikariCP for
better performance and reliability. Reduces connection
overhead by 40% in load tests.
```

```
Fix off-by-one error in pagination

Correct page calculation to prevent skipping the last
item on each page. Adds regression test.

Fixes #789
```

**Bad commit messages:**
```
Fixed stuff                           # Too vague
Updated files                         # Not descriptive
asdfasdf                             # Meaningless
Fixed bug (really important!!!)      # Unprofessional
Changed a lot of things              # Not specific
```

### Commit Message Best Practices

1. **Use the imperative mood**: "Add feature" not "Added feature" or "Adds feature"
2. **Capitalize the first letter**: "Fix bug" not "fix bug"
3. **No period at the end** of the summary line
4. **Separate subject from body** with a blank line
5. **Limit the subject line** to 50 characters
6. **Wrap the body** at 72 characters
7. **Explain what and why**, not how (the code shows how)
8. **Reference issues** when relevant

### Amending Commits

Sometimes you need to modify the most recent commit:

```bash
# Change the commit message
git commit --amend

# Add forgotten changes to the last commit
git add forgotten-file.js
git commit --amend --no-edit

# Amend and change the message
git add style.css
git commit --amend -m "Add user profile page with styling"
```

**Warning**: Only amend commits that haven't been pushed to a shared repository. Amending rewrites history, which can cause problems for collaborators.

## Viewing Commit History with git log

The `git log` command shows your commit history.

### Basic Log Views

```bash
# Standard log output
git log

# Condensed one-line format
git log --oneline

# Show last 5 commits
git log -5

# Show commits with file changes
git log --stat

# Show commits with full diff
git log -p
```

### Formatted Output

```bash
# Pretty format with graph
git log --graph --oneline --decorate

# Custom format
git log --pretty=format:"%h - %an, %ar : %s"

# Graph view with all branches
git log --oneline --graph --all --decorate
```

**Format placeholders:**
- `%h`: Abbreviated commit hash
- `%an`: Author name
- `%ar`: Author date, relative
- `%s`: Subject (commit message)
- `%d`: Ref names (branches, tags)

### Filtering Commits

```bash
# Commits by author
git log --author="John Doe"

# Commits since date
git log --since="2024-01-01"
git log --since="2 weeks ago"

# Commits in date range
git log --since="2024-01-01" --until="2024-12-31"

# Commits affecting specific file
git log README.md

# Commits with message containing text
git log --grep="bug fix"

# Commits that added or removed a specific string
git log -S"function_name"
```

### Useful Combinations

```bash
# Visual branch history
git log --graph --oneline --decorate --all

# Detailed recent history
git log -10 --stat --oneline

# Search for specific changes
git log -p -S"API_KEY" --oneline

# Author activity summary
git shortlog
git shortlog -sn  # Summarized with counts, sorted
```

## What Makes a Good Commit

Good commits are atomic, focused, and well-documented.

### Characteristics of Good Commits

1. **Atomic**: Contains one logical change
   - Fix one bug, add one feature, refactor one component
   - Can be reverted without affecting other changes

2. **Complete**: Doesn't break the build
   - Code compiles/runs after the commit
   - Tests pass
   - No incomplete features

3. **Focused**: Single purpose
   - Don't mix refactoring with new features
   - Don't fix multiple unrelated bugs

4. **Well-documented**: Clear commit message
   - Explains what changed and why
   - Provides context for future developers

### Examples: Good vs Bad Commits

**Bad - Too Large:**
```
Commit: "Update application"
Changes:
  - Add user authentication
  - Refactor database layer
  - Fix CSS styling
  - Update dependencies
  - Add logging
```

**Good - Atomic Commits:**
```
Commit 1: "Add user authentication system"
Commit 2: "Refactor database connection pooling"
Commit 3: "Fix header alignment in navigation"
Commit 4: "Update dependencies to latest versions"
Commit 5: "Add structured logging with Winston"
```

**Bad - Incomplete:**
```
Commit: "Start adding payment processing"
Changes:
  - Half-implemented Stripe integration
  - Code doesn't compile
  - Tests commented out
```

**Good - Complete:**
```
Commit: "Add Stripe payment processing"
Changes:
  - Complete Stripe integration
  - Payment form with validation
  - Backend payment processing
  - Comprehensive tests
  - Error handling
```

## Common Staging and Committing Patterns

### Pattern 1: Feature Development

```bash
# Work on feature
# Stage and review changes
git add src/auth/
git status
git diff --cached

# Commit the feature
git commit -m "Add OAuth2 authentication support"
```

### Pattern 2: Incremental Commits

```bash
# Make several related changes
# Commit incrementally for better history

git add models/user.js
git commit -m "Add User model with validation"

git add controllers/auth.js
git commit -m "Add authentication controller"

git add routes/auth.js
git commit -m "Add authentication routes"

git add tests/auth.test.js
git commit -m "Add authentication tests"
```

### Pattern 3: Selective Staging

```bash
# Modified multiple files but want separate commits
git status
# Shows: index.html, style.css, script.js all modified

# Commit changes separately
git add index.html
git commit -m "Update homepage content"

git add style.css
git commit -m "Improve responsive layout"

git add script.js
git commit -m "Fix navigation toggle"
```

### Pattern 4: Review Before Committing

```bash
# Always review before committing
git status                    # What's changed?
git diff                      # What are the changes?
git add .
git diff --cached            # What's being committed?
git commit
```

### Pattern 5: Commit Message Template

Create a template file `.gitmessage`:
```
# <type>: <subject>

# <body>

# <footer>

# Type: feat, fix, docs, style, refactor, test, chore
# Subject: Imperative mood, lowercase, no period
# Body: Explain what and why, not how
# Footer: Reference issues, breaking changes
```

Configure Git to use it:
```bash
git config --global commit.template ~/.gitmessage
```

### Pattern 6: Checking Staged Changes

```bash
# Before committing, review exactly what's staged
git diff --staged
# or
git diff --cached

# Show summary of staged changes
git status -sb
```

## Quick Reference

### Essential Commands

```bash
# Staging
git add <file>              # Stage specific file
git add .                   # Stage all changes
git add -p                  # Interactive staging

# Committing
git commit -m "message"     # Commit with message
git commit -am "message"    # Stage tracked files and commit
git commit --amend          # Modify last commit

# Viewing
git status                  # Check status
git diff                    # View unstaged changes
git diff --staged           # View staged changes
git log                     # View commit history
git log --oneline          # Condensed history

# Unstaging
git reset HEAD <file>       # Unstage file
git restore --staged <file> # Unstage file (Git 2.23+)
```

### Commit Message Template

```
<type>: <subject>

<body>

<footer>
```

**Types**: feat, fix, docs, style, refactor, test, chore

### Best Practices Summary

1. Commit early and often
2. Write clear, descriptive commit messages
3. Keep commits atomic and focused
4. Review changes before committing
5. Don't commit broken code
6. Use meaningful commit messages that explain "why"
7. Reference related issues
8. Don't commit sensitive information (passwords, API keys)

<hr>

[Previous](gitRepositories.md) -- [Up](README.md) -- [Next](gitBranching.md)
