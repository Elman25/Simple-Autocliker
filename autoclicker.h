// autoclicker.h
#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout> // Included for layout management
#include <QWidget>     // Included for central widget
#include <QPoint>      // For storing mouse coordinates

// Forward declarations for X11 types.
// The actual X11 includes are moved to autoclicker.cpp to avoid conflicts.
struct _XDisplay;
typedef struct _XDisplay Display;

class AutoClicker : public QMainWindow
{
    Q_OBJECT

public:
    AutoClicker(QWidget *parent = nullptr);
    ~AutoClicker();

private slots:
    // This slot is called when the start/stop button is clicked.
    void toggleClicking();
    // This slot is called by the main click timer at the specified interval.
    void performClick();
    // This slot is called when the initial delay timer times out.
    void handleDelayTimeout();
    // This slot is called by a separate timer to check cursor position.
    void checkCursorPosition(); // Re-introduced

private:
    // --- UI Elements ---
    QPushButton *toggleButton;
    QSpinBox *intervalSpinBox;
    QLabel *statusLabel;
    QLabel *intervalLabel;

    // --- Core Logic ---
    QTimer *clickTimer;         // Timer for repetitive clicks
    QTimer *delayTimer;         // Timer for initial 10-second delay
    QTimer *cursorCheckTimer;   // Timer for continuously checking cursor position (Re-introduced)

    bool isClicking;            // True when autoclicking is active
    bool isDelayActive;         // True when in the initial 10-second delay phase
    QPoint fixedClickPos;       // Stores the position where clicking should occur (Re-introduced)

    // --- X11 Specifics ---
    Display *display; // Represents the connection to the X server.

    // Helper function to simulate a mouse click.
    void simulateMouseClick();

    // Function to stop all clicking and reset UI.
    void stopClicking();
};

#endif // AUTOCLICKER_H
