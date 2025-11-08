---
layout: default
title: Git Repositories
---

### Git Repositories

## What is a Git Repository?

A Git repository (or "repo") is a directory that contains all of your project files along with the complete history of changes made to those files. Think of it as a special folder that Git watches and tracks, recording every modification, addition, and deletion you make over time.

A repository contains:
- Your project files and directories
- A hidden `.git` directory that stores all version control information
- Metadata about commits, branches, and repository history
- Configuration settings for the repository

## Creating a New Repository

### Using `git init`

When you're starting a brand new project from scratch, use `git init` to create a new Git repository:

```bash
# Navigate to your project directory
cd my-project

# Initialize a new Git repository
git init
```

This creates a new `.git` directory in your current folder, turning it into a Git repository. You'll see a message like:

```
Initialized empty Git repository in /path/to/my-project/.git/
```

**When to use `git init`:**
- Starting a completely new project
- Adding version control to an existing project that isn't tracked yet
- Creating a local repository before pushing to a remote service

### Example Scenario

```bash
# Create a new project directory
mkdir website-project
cd website-project

# Initialize Git
git init

# Create your first file
echo "# My Website" > README.md

# Add and commit
git add README.md
git commit -m "Initial commit"
```

## Cloning Existing Repositories

### Using `git clone`

When you want to work on an existing project, use `git clone` to create a local copy of a remote repository:

```bash
# Clone a repository
git clone https://github.com/username/repository.git

# Clone into a specific directory name
git clone https://github.com/username/repository.git my-folder-name

# Clone a specific branch
git clone -b branch-name https://github.com/username/repository.git
```

**When to use `git clone`:**
- Contributing to an existing project
- Creating a local copy of your own remote repository
- Downloading open-source projects to study or modify

### Clone vs Init

| Scenario | Use This |
|----------|----------|
| New project from scratch | `git init` |
| Existing project on GitHub/GitLab | `git clone` |
| Adding Git to existing local files | `git init` |
| Contributing to someone else's project | `git clone` |

## Repository Structure: The `.git` Directory

When you initialize or clone a repository, Git creates a `.git` directory that contains all the internal tracking information. Here's what's inside:

```
.git/
├── HEAD              # Points to current branch
├── config            # Repository-specific settings
├── description       # Repository description (rarely used)
├── hooks/            # Scripts that run on Git events
├── info/             # Global exclude file
├── objects/          # All content (commits, files, etc.)
├── refs/             # Pointers to commits (branches, tags)
│   ├── heads/        # Local branches
│   └── tags/         # Tags
└── logs/             # History of branch updates
```

**Important:** Never manually edit files in the `.git` directory unless you know exactly what you're doing. Git manages this directory automatically.

## Local vs Remote Repositories

### Local Repository

A local repository exists on your computer. All Git operations (commits, branches, merges) happen locally first, which makes Git fast and allows you to work offline.

```bash
# Your local work happens here
git add .
git commit -m "Made changes"
git branch new-feature
```

### Remote Repository

A remote repository is hosted on a server (like GitHub, GitLab, or Bitbucket). It serves as a central location where team members can share and sync their work.

```bash
# Connect to a remote repository
git remote add origin https://github.com/username/repo.git

# Push your local changes to remote
git push origin main

# Pull changes from remote
git pull origin main
```

### The Relationship

```
Your Computer                          Remote Server
┌──────────────────┐                  ┌──────────────────┐
│ Local Repository │  ←── clone ───   │ Remote Repository│
│                  │                   │   (GitHub, etc.) │
│   git commit     │  ── push ──→     │                  │
│   git add        │  ←── pull ───    │                  │
└──────────────────┘                  └──────────────────┘
```

## Checking Repository Status

### Using `git status`

The `git status` command shows you the current state of your repository:

```bash
git status
```

**Sample output:**

```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   index.html

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   style.css

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        script.js
```

This tells you:
- Which branch you're on
- Files ready to commit (staged)
- Modified files not yet staged
- Untracked files Git isn't watching yet

## Tracked vs Untracked Files

### Tracked Files

Files that Git is actively monitoring for changes. Once you've added a file with `git add` and committed it, Git tracks it.

```bash
# These files are tracked
git add README.md
git commit -m "Add README"
```

**Characteristics:**
- Git detects modifications
- Appears in `git status` when changed
- Included in version history

### Untracked Files

Files that exist in your working directory but Git isn't monitoring yet. New files start as untracked.

```bash
# Create a new file (it's untracked)
echo "console.log('hello');" > app.js

# Check status
git status
# Shows: Untracked files: app.js

# Track it by staging and committing
git add app.js
git commit -m "Add app.js"
```

**Characteristics:**
- Not in version control history
- Git ignores changes to them
- Won't be included in commits until you `git add` them

## The `.gitignore` File

### What is `.gitignore`?

The `.gitignore` file tells Git which files and directories to ignore and not track. This is essential for excluding:
- Build artifacts and compiled code
- Dependencies that can be downloaded
- Sensitive information (passwords, API keys)
- System files and IDE configurations
- Temporary files

### How to Use `.gitignore`

Create a file named `.gitignore` in your repository root:

```bash
# Create .gitignore file
touch .gitignore

# Edit it to add patterns
nano .gitignore
```

### Common `.gitignore` Patterns

**General patterns:**

```gitignore
# Ignore specific file
secrets.txt

# Ignore all files with extension
*.log
*.tmp

# Ignore entire directory
node_modules/
build/
dist/

# Ignore files in any directory
**/*.cache

# Exception: don't ignore this file
!important.log
```

**For a Node.js project:**

```gitignore
# Dependencies
node_modules/
npm-debug.log
yarn-error.log

# Build output
dist/
build/

# Environment variables
.env
.env.local

# IDE
.vscode/
.idea/

# OS files
.DS_Store
Thumbs.db
```

**For a Python project:**

```gitignore
# Byte-compiled files
__pycache__/
*.py[cod]
*$py.class

# Virtual environment
venv/
env/
ENV/

# Distribution
dist/
build/
*.egg-info/

# IDE
.vscode/
.idea/

# Environment
.env
```

**For a Java project:**

```gitignore
# Compiled class files
*.class

# Package files
*.jar
*.war
*.ear

# Build directories
target/
build/

# IDE
.idea/
*.iml
.eclipse/

# Log files
*.log
```

### Pattern Rules

| Pattern | Meaning |
|---------|---------|
| `file.txt` | Ignore file.txt in any directory |
| `/file.txt` | Ignore file.txt only in root |
| `*.log` | Ignore all .log files |
| `logs/` | Ignore entire logs directory |
| `!important.log` | Exception: track this file |
| `**/temp` | Ignore temp in any directory depth |

### Important Notes

1. **Add `.gitignore` early:** Create it when you initialize your repository
2. **Already tracked files:** If you add a file to `.gitignore` after it's been committed, Git will still track it. You need to untrack it first:

```bash
# Remove from tracking but keep local file
git rm --cached filename

# Commit the change
git commit -m "Stop tracking filename"
```

3. **Global `.gitignore`:** You can create a global ignore file for patterns you want ignored in all your repositories:

```bash
git config --global core.excludesfile ~/.gitignore_global
```

### Finding `.gitignore` Templates

GitHub maintains a collection of useful `.gitignore` templates for different programming languages and frameworks at [github.com/github/gitignore](https://github.com/github/gitignore).

<hr>

[Previous](gitSetup.md) -- [Up](README.md) -- [Next](gitCommitting.md)
