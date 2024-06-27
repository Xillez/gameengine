/**
 * Base class that add an enabled state.
 */
class Enable
{
public:
    /**
     * Get whether object is enabled or not.
     *
     * @returns - boolean - true if enabled, false otherwise.
     */
    bool isEnabled();

    /**
     * Set whether object is enabled or not.
     *
     * @param state - boolean - Wanted state.
     */
    void setEnabled(bool state);

protected:
    bool enabled = true;
};