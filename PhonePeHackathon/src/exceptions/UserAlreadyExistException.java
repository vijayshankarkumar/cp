package exceptions;

public class UserAlreadyExistException extends Exception{
    private String message;

    public UserAlreadyExistException(String message) {
        super(message);
        this.message = message;
    }

    @Override
    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
