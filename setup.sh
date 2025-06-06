#!/bin/bash
# Setup dependencies for the multi-language OpenAI demo
set -e

# Update package list
apt-get update

# Install common packages
apt-get install -y \
    python3-pip \
    nodejs npm \
    golang-go \
    rustc cargo \
    openjdk-17-jdk maven \
    g++ libcurl4-openssl-dev nlohmann-json3-dev

# Install Python library
pip3 install --no-cache-dir openai

# Install Node.js library
npm install openai

# Pre-fetch Jackson for Java using Maven
mvn -q dependency:get -Dartifact=com.fasterxml.jackson.core:jackson-databind:2.17.1
