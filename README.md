# Team-4's README.
Team-4's description.
# 🏙️ VScoders and the Jetbrainstormers👨‍💻 - City Builder Simulation

<div align="center"> 
  <img src="https://media.giphy.com/media/6N70OZ9QZgWGOSLb52/giphy.gif" alt="Cyberpunk GIF" width="480" height="271"/> 
  <br> 
  <a href="https://giphy.com/gifs/netflix-cyberpunk-edgerunners-6N70OZ9QZgWGOSLb52">via GIPHY</a> 
</div>

<p style="font-size: 20px; font-family: 'Georgia', serif;">
  Welcome to <b>VScoders and the Jetbrainstormers👨‍💻</b> GitHub repository! This project, developed for the <b>University of Pretoria COS 214</b>, is a city-building simulation game implemented in C++. Our goal is to manage and grow a virtual city by balancing infrastructure, resources, citizens' needs, and government policies, using various <b>design patterns</b>.
</p>

---

## 🚀 Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Design Patterns](#design-patterns)
- [Collaborators](#collaborators)
- [License](#license)

---

## 🏗️ Introduction

<p style="font-size: 18px; font-family: 'Helvetica', sans-serif;">
In this project, you’ll build and manage your own virtual city, using object-oriented design principles and patterns. Our simulation handles core city functions like:
</p>
<ul style="font-size: 18px; font-family: 'Helvetica', sans-serif;">
  <li>Building construction</li>
  <li>Resource allocation</li>
  <li>Tax collection</li>
  <li>Citizen management</li>
</ul>

---

## ✨ Features

<ul style="font-size: 18px; font-family: 'Courier New', monospace;">
  <li><b>Dynamic Building Management</b>: Residential, Commercial, Industrial, and Landmark types.</li>
  <li><b>Resource Management</b>: Efficient distribution of power, water, and waste.</li>
  <li><b>Transportation System</b>: Roads, trains, public transit.</li>
  <li><b>Government and Taxation</b>: Tax collection and budget allocation.</li>
  <li><b>Citizen Satisfaction</b>: Ensure the well-being of the city's population.</li>
  <li><b>Real-time Simulation</b>: Turn-based or real-time city updates.</li>
</ul>

<div align="center"> 
  <img src="https://media.giphy.com/media/yHCXr6wBvIZXE4H9kd/giphy.gif" alt="Bulwark Falconeer GIF" width="480" height="271"/>
  <br> 
  <a href="https://giphy.com/gifs/WiredP-chronicles-bulwark-falconeer-yHCXr6wBvIZXE4H9kd">via GIPHY</a>
</div>

---

## ⚙️ Installation

<p style="font-size: 18px; font-family: 'Lucida Console', monospace;">
To run the City Builder Simulation, follow these steps:
</p>

```bash
1. Clone the repository:
   git clone https://github.com/your-repo/city-builder.git
   cd city-builder

2. Build the project:
   make all

3. Run the simulation:
   ./city_builder
```

> 💡 <span style="font-size: 18px; font-family: 'Arial', sans-serif;">Make sure you have a C++ compiler and **Make** installed.</span>

---

## 🕹️ Usage

<p style="font-size: 18px; font-family: 'Georgia', serif;">
Upon running the program, you'll be presented with a command-line interface to manage the city's components. Follow the in-game prompts to:
</p>

<ul style="font-size: 18px; font-family: 'Georgia', serif;">
  <li>Build and manage different structures (residential, commercial, etc.)</li>
  <li>Adjust tax rates</li>
  <li>Allocate resources</li>
  <li>Monitor citizen satisfaction</li>
</ul>

---

## 🧠 Design Patterns

<p style="font-size: 18px; font-family: 'Georgia', serif;">
This project applies various design patterns to manage different components of the city. These include:
</p>

<ul style="font-size: 18px; font-family: 'Georgia', serif;">
  <li><b>Singleton</b> for managing global resources.</li>
  <li><b>Factory</b> for creating new buildings.</li>
  <li><b>Observer</b> for updating citizen satisfaction dynamically.</li>
  <li><b>Strategy</b> for handling different taxation policies.</li>
  <li><b>Command</b> for handling user interactions.</li>
  <li><b>Mediator</b> for facilitating communication between different components.</li>
  <li><b>State</b> for managing the state of various entities.</li>
  <li><b>Chain of Responsibility</b> for processing resource approval requests.</li>
  <li><b>Iterator</b> for traversing collections of farm units.</li>
  <li><b>Builder</b> for constructing complex objects step by step.</li>
  <li><b>Template</b> for defining the skeleton of an algorithm.</li>
  <li><b>Prototype</b> for creating new objects by copying existing ones.</li>
  <li><b>Adapter</b> for integrating legacy systems with new interfaces.</li>
</ul>

### Problem it Solves and Usage in Diagram

- **Factory Method**
  - **Problem it Solves**: Allows the creation of different building types without specifying their concrete classes.
  - **Usage in Diagram**: Factories like ResidentialBuildingBuilder, CommercialBuildingBuilder, IndustrialBuildingBuilder, and LandmarkBuildingBuilder create specific building types.

- **Strategy**
  - **Problem it Solves**: Switches between different resource allocation strategies or tax types dynamically.
  - **Usage in Diagram**: ResourceAllocationStrategy allows dynamic resource allocation strategies (e.g., PriorityDistributionStrategy, EqualDistributionStrategy). Also used for switching tax types.

- **Command**
  - **Problem it Solves**: Encapsulates requests (e.g., tax setting, budget allocation) as objects for flexible execution and undo functionality.
  - **Usage in Diagram**: GovCommand and its concrete implementations (SetTaxCommand, AllocateBudgetCommand, EnforcePolicyCommand) allow the government to execute and undo commands.

- **Observer**
  - **Problem it Solves**: Automatically updates dependent objects when the state of a subject changes.
  - **Usage in Diagram**: CitizenObserver and CityGrowthObserver notify other entities about changes in population growth, resource usage, or citizen satisfaction.

- **Chain of Responsibility**
  - **Problem it Solves**: Passes resource approval requests through a chain of handlers for validation (e.g., budget, policy, availability).
  - **Usage in Diagram**: ResourceApprovalHandler and its subclasses (BudgetApprovalHandler, PolicyCheckHandler, ResourceAvailabilityHandler) process resource requests in a chain.

- **Mediator**
  - **Problem it Solves**: Coordinates interactions between components (e.g., utilities, buildings, citizens) without direct interaction between them.
  - **Usage in Diagram**: UtilityMediator and CityUtilityMediator mediate between utilities like PowerPlant, WaterSupply, and city infrastructure, ensuring coordinated resource distribution.

- **State**
  - **Problem it Solves**: Changes behavior based on an internal state, such as citizen satisfaction or employment.
  - **Usage in Diagram**: CitizenState transitions between states like EmployedState, UnemployedState, SatisfiedState, and UnsatisfiedState, affecting how citizens react to the city's economy and taxes.

- **Builder Pattern**
  - **Problem it Solves**: Constructs complex objects (buildings) step-by-step, allowing for flexible creation.
  - **Usage in Diagram**: BuildingBuilder and its subclasses (e.g., ResidentialBuildingBuilder, CommercialBuildingBuilder) build various types of buildings using flexible construction steps.

- **Prototype Pattern**
  - **Problem it Solves**: Allows the cloning of existing building objects to create new instances efficiently.
  - **Usage in Diagram**: BuildingPrototype clones buildings like ResidentialBuilding, CommercialBuilding, etc., for efficient replication in city expansion.

> UML Diagrams and more details on patterns can be found in the project documentation.


---

## 🧑‍💻 Collaborators

Here’s our awesome team behind the **VScoders and the Jetbrainstormers👨‍💻**:

<table>
  <thead>
    <tr>
      <th style="font-size: 20px; font-family: 'Verdana', sans-serif;">Profile Picture</th>
      <th style="font-size: 20px; font-family: 'Verdana', sans-serif;">GitHub Handle</th>
      <th style="font-size: 20px; font-family: 'Verdana', sans-serif;">Name</th>
      <th style="font-size: 20px; font-family: 'Verdana', sans-serif;">Student Number</th>
      <th style="font-size: 20px; font-family: 'Verdana', sans-serif;">Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><img src="https://github.com/abdulrasaqzainab.png" width="80"></td>
      <td><a href="https://github.com/abdulrasaqzainab" style="font-size: 18px;">@abdulrasaqzainab</a></td>
      <td style="font-size: 18px;">Miss. Zainab Abdulrasaq</td>
      <td style="font-size: 18px;">u22566202</td>
      <td style="font-size: 18px;">Buildings: Infrastructure and Building Manager</td>
    </tr>
    <tr>
      <td><img src="https://github.com/Naven13.png" width="80"></td>
      <td><a href="https://github.com/Naven13" style="font-size: 18px;">@Naven13</a></td>
      <td style="font-size: 18px;">Mr. Navendran Naidoo</td>
      <td style="font-size: 18px;">u21512494</td>
      <td style="font-size: 18px;">Resources: Resource Management Specialist</td>
    </tr>
    <tr>
      <td><img src="https://github.com/RudolphLamp.png" width="80"></td>
      <td><a href="https://github.com/RudolphLamp" style="font-size: 18px;">@RudolphLamp</a></td>
      <td style="font-size: 18px;">Mr. Rudolph Lamprecht</td>
      <td style="font-size: 18px;">u20598425</td>
      <td style="font-size: 18px;">Government: City Governance Manager</td>
    </tr>
    <tr>
      <td><img src="https://github.com/ShaydenNaidoo.png" width="80"></td>
      <td><a href="https://github.com/ShaydenNaidoo" style="font-size: 18px;">@ShaydenNaidoo</a></td>
      <td style="font-size: 18px;">Mr. Shayden Naidoo</td>
      <td style="font-size: 18px;">u23599236</td>
      <td style="font-size: 18px;">Team lead and Taxes: Financial and Taxation Strategist</td>
    </tr>
    <tr>
      <td><img src="https://github.com/Sammy-2903.png" width="80"></td>
      <td><a href="https://github.com/Sammy-2903" style="font-size: 18px;">@Sammy-2903</a></td>
      <td style="font-size: 18px;">Mr. Samvit Prakash</td>
      <td style="font-size: 18px;">u23525119</td>
      <td style="font-size: 18px;">Transportation: Transportation Systems Coordinator</td>
    </tr>
    <tr>
      <td><img src="https://github.com/blizs.png" width="80"></td>
      <td><a href="https://github.com/blizs" style="font-size: 18px;">@blizs</a></td>
      <td style="font-size: 18px;">Mr. Arnaud Strydom</td>
      <td style="font-size: 18px;">u23536013</td>
      <td style="font-size: 18px;">Citizens: Citizen Welfare and Demographics Analyst</td>
    </tr>
    <tr>
      <td><img src="https://github.com/NeoMachabaUP.png" width="80"></td>
      <td><a href="https://github.com/NeoMachabaUP" style="font-size: 18px;">@NeoMachabaUP</a></td>
      <td style="font-size: 18px;">Mr. Neo Machaba</td>
      <td style="font-size: 18px;">u23002167</td>
      <td style="font-size: 18px;">Utilities: Utilities and Service Manager</td>
    </tr>
  </tbody>
</table>



## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
