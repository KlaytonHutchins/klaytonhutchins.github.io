---
layout: default
title: Docker Basics
---

### What is Docker?

Docker is a platform for developing, shipping, and running applications in containers. Containers allow developers to package an application with all its dependencies into a standardized unit for software development.

### Why Docker?

Docker solves several common problems in software development:

* **"It works on my machine"** - Docker ensures your application runs the same way everywhere, from development to production.

* **Dependency management** - All dependencies are bundled with the application in the container.

* **Resource efficiency** - Containers are lightweight compared to virtual machines.

* **Fast deployment** - Containers can be started in seconds.

* **Isolation** - Applications run in isolated environments without interfering with each other.

### Docker vs Virtual Machines

| Feature | Docker Containers | Virtual Machines |
|---------|------------------|------------------|
| Size | Megabytes | Gigabytes |
| Startup time | Seconds | Minutes |
| Resource usage | Shares host OS kernel | Requires full OS |
| Isolation | Process-level | Hardware-level |
| Portability | High | Medium |

### Key Concepts

#### Container
A runnable instance of an image. Think of it as a lightweight, isolated environment where your application runs.

#### Image
A read-only template with instructions for creating a container. Images are built from a Dockerfile.

#### Dockerfile
A text file containing commands to assemble an image.

#### Registry
A repository for Docker images. Docker Hub is the default public registry.

#### Docker Engine
The runtime that builds and runs containers on your machine.

### Installing Docker

Docker is available for Linux, macOS, and Windows.

**macOS and Windows:**
- Install Docker Desktop from [docker.com](https://www.docker.com/products/docker-desktop)

**Linux:**
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io

# Verify installation
docker --version
```

### Verifying Installation

After installation, verify Docker is working:

```bash
docker run hello-world
```

This command:
1. Downloads the `hello-world` image from Docker Hub
2. Creates a container from that image
3. Runs the container
4. Displays a welcome message

> ### Skill++
> Docker was released in 2013 by Solomon Hykes. It popularized container technology, though Linux containers (LXC) existed since 2008.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](dockerImages.md)
