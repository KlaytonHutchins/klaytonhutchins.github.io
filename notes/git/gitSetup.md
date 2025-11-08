---
layout: default
title: Git Setup and Configuration
---

### Git Setup and Configuration

Before you can start using Git, you need to install it and configure it properly. This guide will walk you through the installation process and essential configuration steps.

---

## Installing Git

### Windows

**Option 1: Official Git for Windows**

1. Download the installer from [git-scm.com](https://git-scm.com/download/windows)
2. Run the downloaded `.exe` file
3. Follow the installation wizard (recommended settings are usually fine)
4. During installation, you can choose:
   - Your default editor (Vim, Nano, VS Code, etc.)
   - PATH environment settings (recommended: "Git from the command line and also from 3rd-party software")
   - Line ending conversions (recommended: "Checkout Windows-style, commit Unix-style")

**Option 2: Using Package Manager (Chocolatey)**

```bash
choco install git
```

**Option 3: Using Package Manager (Winget)**

```bash
winget install --id Git.Git -e --source winget
```

### macOS

**Option 1: Using Homebrew (Recommended)**

```bash
brew install git
```

**Option 2: Using Xcode Command Line Tools**

```bash
xcode-select --install
```

This installs Apple's version of Git, which may be slightly outdated.

**Option 3: Official Installer**

Download from [git-scm.com](https://git-scm.com/download/mac) and run the installer.

### Linux

**Debian/Ubuntu:**

```bash
sudo apt update
sudo apt install git
```

**Fedora:**

```bash
sudo dnf install git
```

**Arch Linux:**

```bash
sudo pacman -S git
```

**CentOS/RHEL:**

```bash
sudo yum install git
```

---

## Verifying Installation

After installation, verify that Git is properly installed by checking the version:

```bash
git --version
```

You should see output similar to:

```
git version 2.42.0
```

The exact version number will vary depending on when you installed Git.

---

## Essential Configuration

Git needs to know who you are before you can make commits. At minimum, you must configure your name and email address.

### Setting Your Identity

**Configure your name:**

```bash
git config --global user.name "Your Name"
```

**Configure your email:**

```bash
git config --global user.email "your.email@example.com"
```

**Why this matters:** Every Git commit includes this information, and it's permanently baked into the commits you create. For GitHub, GitLab, or other platforms, use the email associated with your account.

**Example:**

```bash
git config --global user.name "Jane Doe"
git config --global user.email "jane.doe@example.com"
```

### Setting Your Default Editor

Git uses a text editor for commit messages and other text input. Choose one you're comfortable with:

**VS Code:**

```bash
git config --global core.editor "code --wait"
```

**Sublime Text:**

```bash
git config --global core.editor "subl -n -w"
```

**Nano:**

```bash
git config --global core.editor "nano"
```

**Vim:**

```bash
git config --global core.editor "vim"
```

**Emacs:**

```bash
git config --global core.editor "emacs"
```

**Why this matters:** When you commit changes without a message (using `git commit` without `-m`), Git opens this editor for you to write your commit message.

### Line Ending Preferences

Different operating systems use different characters to represent line endings in text files. Git can handle this automatically.

**Windows:**

```bash
git config --global core.autocrlf true
```

This converts LF to CRLF on checkout and CRLF to LF on commit.

**macOS/Linux:**

```bash
git config --global core.autocrlf input
```

This converts CRLF to LF on commit but doesn't convert on checkout.

**Why this matters:** This prevents issues when collaborating with people on different operating systems and keeps your repository consistent.

### Default Branch Name

Modern Git repositories use `main` as the default branch name instead of `master`:

```bash
git config --global init.defaultBranch main
```

**Why this matters:** This sets the default branch name for new repositories you create with `git init`.

---

## Configuration Levels

Git has three levels of configuration, each overriding the previous level:

### System Level

Applies to every user on the system and all their repositories.

```bash
git config --system user.name "System User"
```

**Location:**
- Linux/macOS: `/etc/gitconfig`
- Windows: `C:\Program Files\Git\etc\gitconfig`

**Note:** Requires administrator/root privileges.

### Global Level

Applies to all repositories for the current user.

```bash
git config --global user.name "Your Name"
```

**Location:**
- Linux/macOS: `~/.gitconfig` or `~/.config/git/config`
- Windows: `C:\Users\YourUsername\.gitconfig`

**Most commonly used** for personal settings.

### Local Level (Repository)

Applies only to the specific repository where you set it.

```bash
git config --local user.name "Project Specific Name"
```

Or simply:

```bash
git config user.name "Project Specific Name"
```

**Location:** `.git/config` inside the repository

**Use case:** Different email for work vs. personal projects, or specific settings for a particular project.

### Priority Order

Local > Global > System

Settings at a more specific level override those at a broader level.

---

## Checking Your Configuration

### View All Settings

```bash
git config --list
```

This shows all settings from all levels.

### View Settings with Origins

```bash
git config --list --show-origin
```

This shows where each setting is coming from (which config file).

### View a Specific Setting

```bash
git config user.name
```

### View Global Settings Only

```bash
git config --global --list
```

### View Local Settings Only

```bash
git config --local --list
```

---

## Setting Up SSH Keys (Optional but Recommended)

SSH keys provide a secure way to authenticate with remote repositories like GitHub, GitLab, or Bitbucket without entering your password each time.

### Check for Existing SSH Keys

```bash
ls -al ~/.ssh
```

Look for files named `id_rsa.pub`, `id_ecdsa.pub`, `id_ed25519.pub`, etc.

### Generate a New SSH Key

**Using Ed25519 (Recommended):**

```bash
ssh-keygen -t ed25519 -C "your.email@example.com"
```

**Using RSA (if Ed25519 isn't supported):**

```bash
ssh-keygen -t rsa -b 4096 -C "your.email@example.com"
```

Press Enter to accept the default file location, then optionally enter a passphrase.

### Add SSH Key to SSH Agent

**Start the SSH agent:**

```bash
eval "$(ssh-agent -s)"
```

**Add your key:**

```bash
ssh-add ~/.ssh/id_ed25519
```

(Replace `id_ed25519` with `id_rsa` if you used RSA)

### Add SSH Key to Your Git Hosting Service

**Copy your public key to clipboard:**

**macOS:**

```bash
pbcopy < ~/.ssh/id_ed25519.pub
```

**Linux:**

```bash
cat ~/.ssh/id_ed25519.pub | xclip -selection clipboard
```

Or simply:

```bash
cat ~/.ssh/id_ed25519.pub
```

Then manually copy the output.

**Windows (Git Bash):**

```bash
clip < ~/.ssh/id_ed25519.pub
```

**Add to GitHub:**
1. Go to Settings > SSH and GPG keys
2. Click "New SSH key"
3. Paste your key and give it a descriptive title
4. Click "Add SSH key"

**Add to GitLab:**
1. Go to Preferences > SSH Keys
2. Paste your key in the "Key" field
3. Add a title and optional expiration date
4. Click "Add key"

### Test Your SSH Connection

**GitHub:**

```bash
ssh -T git@github.com
```

**GitLab:**

```bash
ssh -T git@gitlab.com
```

You should see a success message like: "Hi username! You've successfully authenticated..."

---

## Common Initial Setup Best Practices

### 1. Configure Helpful Aliases

Aliases can save you time by creating shortcuts for common commands:

```bash
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global alias.visual 'log --oneline --graph --decorate --all'
```

Now you can use `git st` instead of `git status`.

### 2. Enable Colored Output

Make Git output easier to read:

```bash
git config --global color.ui auto
```

### 3. Set Default Push Behavior

Configure how Git handles pushes:

```bash
git config --global push.default simple
```

Or for Git 2.0+:

```bash
git config --global push.default current
```

### 4. Enable Credential Caching

Avoid typing your password repeatedly:

**macOS:**

```bash
git config --global credential.helper osxkeychain
```

**Linux:**

```bash
git config --global credential.helper cache
```

Or for longer timeout (1 hour):

```bash
git config --global credential.helper 'cache --timeout=3600'
```

**Windows:**

```bash
git config --global credential.helper wincred
```

Or use Git Credential Manager:

```bash
git config --global credential.helper manager
```

### 5. Configure Pull Behavior

Specify how Git should reconcile divergent branches:

```bash
git config --global pull.rebase false
```

Options:
- `false` - merge (default)
- `true` - rebase
- `only` - fast-forward only

### 6. Set Up .gitignore Global

Create a global gitignore file for files you never want to commit:

```bash
git config --global core.excludesfile ~/.gitignore_global
```

Then create the file:

```bash
touch ~/.gitignore_global
```

Add common files to ignore (edit with your preferred editor):

```
# macOS
.DS_Store
.AppleDouble
.LSOverride

# Windows
Thumbs.db
Desktop.ini

# Linux
*~

# IDEs
.vscode/
.idea/
*.swp
*.swo

# Logs
*.log
```

---

## Verification Checklist

After completing your setup, verify everything is configured correctly:

```bash
# Check Git version
git --version

# Verify identity
git config user.name
git config user.email

# View all configuration
git config --list

# Test SSH (if configured)
ssh -T git@github.com
```

---

## Next Steps

Now that Git is installed and configured, you're ready to:
- Create your first repository
- Start tracking changes
- Collaborate with others

Your Git configuration is stored in plain text files, so you can always edit them manually or use `git config` commands to make changes later.

<hr>

[Previous](gitBasics.md) -- [Up](README.md) -- [Next](gitRepositories.md)
