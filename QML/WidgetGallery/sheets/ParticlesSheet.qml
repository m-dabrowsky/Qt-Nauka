import QtQuick 2.7
import QtQuick.Particles 2.0
import QtQuick.Particles 2.12

BaseSheet {
    id: root

    ParticleSystem {
        id: particles
        anchors.fill: parent

        // obrazek
        ImageParticle {
            id: leafImage
            anchors.fill: parent
            source: "../assets/leaf.png"
            alpha: 0.0
            alphaVariation: 1.0
            colorVariation: 1.0
            autoRotation: true
            rotation: 180

        }

        Emitter {
            anchors.fill: parent
            emitRate: 50
            lifeSpan: 5000
            velocity: AngleDirection {angle: 10; angleVariation: 180; magnitude: 60; magnitudeVariation: 50}
            size: 30
            sizeVariation: 10
        }
    }



}
