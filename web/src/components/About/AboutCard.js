import React from "react";
import Card from "react-bootstrap/Card";
import { ImPointRight } from "react-icons/im";

function AboutCard() {
  return (
    <Card className="quote-card-view">
      <Card.Body>
        <blockquote className="blockquote mb-0">
          <p style={{ textAlign: "justify" }}>
            Hi Everyone, I am <span className="purple">Andy Lee </span>
            from <span className="purple"> Taiwan.</span>
            <br /> I am a graduate student who possesses strong passion for the CS field 💻 at National Taiwan University.
            <br /><br />
            Additionally, I am currently working as a software developer intern at Acer and AWS Cloud Ambassador.
            <br />
          </p>
        </blockquote>
      </Card.Body>
    </Card>
  );
}

export default AboutCard;
