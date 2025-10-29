---
layout: default
title: Docker Networking
---

### Container Networking Basics

By default, Docker containers can communicate with each other and the outside world. Docker provides several network drivers to control how containers connect.

### Network Drivers

#### Bridge (Default)

Default network driver. Containers on the same bridge network can communicate.

```bash
# Containers use bridge by default
docker run -d --name web nginx
```

**Use cases:**
* Standalone containers
* Multiple containers on same host
* Default choice for most applications

#### Host

Container shares host's network stack. No network isolation.

```bash
# Use host network
docker run --network host nginx
```

**Use cases:**
* Performance-critical applications
* Need to access host network services
* No port mapping needed

#### None

Disables networking for container.

```bash
# No networking
docker run --network none nginx
```

**Use cases:**
* Maximum isolation
* Batch processing jobs
* Security-critical workloads

#### Overlay

Enables communication between containers across multiple Docker hosts.

```bash
# Create overlay network (requires Swarm mode)
docker network create --driver overlay my-overlay
```

**Use cases:**
* Multi-host deployments
* Docker Swarm
* Kubernetes-like orchestration

### Working with Networks

#### List Networks

```bash
# List all networks
docker network ls

# Filter by driver
docker network ls --filter driver=bridge
```

#### Create Network

```bash
# Create bridge network
docker network create my-network

# Create with specific subnet
docker network create --subnet=192.168.1.0/24 my-network

# Create with custom driver
docker network create --driver bridge my-bridge
```

#### Inspect Network

```bash
# View network details
docker network inspect my-network

# View specific field
docker network inspect -f '{{range .Containers}}{{.Name}} {{end}}' my-network
```

#### Connect Container to Network

```bash
# Connect running container
docker network connect my-network my-container

# Connect with alias
docker network connect --alias db my-network postgres

# Disconnect from network
docker network disconnect my-network my-container
```

#### Run Container on Network

```bash
# Run on specific network
docker run -d --network my-network --name web nginx

# Run on multiple networks
docker run -d --network net1 --name app myapp
docker network connect net2 app
```

#### Remove Network

```bash
# Remove network
docker network rm my-network

# Remove all unused networks
docker network prune
```

### Container Communication

#### By Container Name

Containers on the same user-defined network can communicate by name:

```bash
# Create network
docker network create my-app

# Run database
docker run -d --network my-app --name postgres postgres

# Run API (can connect to 'postgres' by name)
docker run -d --network my-app --name api \
  -e DB_HOST=postgres \
  my-api
```

Inside the API container:
```javascript
// Connect using container name
const connection = {
  host: 'postgres',  // Container name
  port: 5432
};
```

#### By IP Address

```bash
# Get container IP
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' postgres

# Connect using IP (less reliable - IPs can change)
docker run -d -e DB_HOST=172.17.0.2 my-api
```

#### Port Publishing

Expose container ports to host:

```bash
# Publish port
docker run -p 8080:80 nginx

# Publish to specific interface
docker run -p 127.0.0.1:8080:80 nginx

# Publish all exposed ports to random ports
docker run -P nginx
```

### Network Isolation Example

```bash
# Create frontend network
docker network create frontend

# Create backend network
docker network create backend

# Web server on frontend only
docker run -d --network frontend --name nginx nginx

# API on both networks
docker run -d --network frontend --name api my-api
docker network connect backend api

# Database on backend only
docker run -d --network backend --name postgres postgres
```

Result:
* nginx can reach api
* api can reach postgres
* nginx cannot reach postgres (isolated)

### DNS Resolution

User-defined networks have built-in DNS:

```bash
# Create network
docker network create my-app

# Run containers
docker run -d --network my-app --name api1 my-api
docker run -d --network my-app --name api2 my-api
docker run -d --network my-app --name lb nginx

# Load balancer can reach api1 and api2 by name
docker exec lb ping api1
docker exec lb ping api2
```

### Network Aliases

Multiple containers can share the same network alias:

```bash
# Create network
docker network create my-app

# Run API instances with same alias
docker run -d --network my-app --network-alias api my-api
docker run -d --network my-app --network-alias api my-api
docker run -d --network my-app --network-alias api my-api

# Clients connect to 'api' (round-robin DNS)
docker run --network my-app curlimages/curl curl http://api:3000
```

### Docker Compose Networking

Docker Compose automatically creates a network for your application:

```yaml
version: '3.8'

services:
  web:
    image: nginx
    # Can connect to 'api' by name

  api:
    image: my-api
    # Can connect to 'db' by name

  db:
    image: postgres
```

#### Custom Networks in Compose

```yaml
version: '3.8'

services:
  web:
    networks:
      - frontend

  api:
    networks:
      - frontend
      - backend

  db:
    networks:
      - backend

networks:
  frontend:
  backend:
```

#### Network Configuration

```yaml
networks:
  frontend:
    driver: bridge

  backend:
    driver: bridge
    ipam:
      config:
        - subnet: 192.168.1.0/24
```

### Common Networking Patterns

#### Microservices

```bash
# Shared network for all services
docker network create microservices

# Service A
docker run -d --network microservices --name service-a service-a

# Service B (can call service-a)
docker run -d --network microservices --name service-b service-b

# Service C (can call both)
docker run -d --network microservices --name service-c service-c
```

#### Web Application

```bash
# Frontend network
docker network create frontend

# Backend network
docker network create backend

# Nginx (public-facing)
docker run -d -p 80:80 --network frontend --name nginx nginx

# App server (connects both)
docker run -d --network frontend --name app my-app
docker network connect backend app

# Database (isolated)
docker run -d --network backend --name postgres postgres
```

#### Development Setup

```bash
# Development network
docker network create dev

# Application
docker run -d --network dev --name app \
  -v $(pwd):/app \
  my-app

# Database
docker run -d --network dev --name db postgres

# Redis
docker run -d --network dev --name cache redis

# All services can communicate by name
```

### Debugging Network Issues

```bash
# Check container networks
docker inspect my-container | grep Networks -A 10

# Test connectivity
docker exec my-container ping other-container

# Check DNS resolution
docker exec my-container nslookup other-container

# View network details
docker network inspect my-network

# List connected containers
docker network inspect -f '{{range .Containers}}{{.Name}} {{end}}' my-network
```

### Best Practices

* **Use user-defined networks** - Better than default bridge
* **Communicate by name** - Not IP address
* **Network isolation** - Separate frontend/backend networks
* **Don't use host network** - Unless necessary for performance
* **Clean up networks** - Remove unused networks regularly
* **Use Docker Compose** - Simplifies multi-container networking
* **Limit exposed ports** - Only publish ports that need external access

> ### Skill++
> Docker's networking is built on Linux namespaces, providing true isolation between containers at the kernel level!

<hr>

[Prev](dockerCompose.md) -- [Up](README.md) -- [Next](dockerVolumes.md)
