package src;

public class Product<T> {
	private T product;
	
	public Product(T product) {
		setProduct(product);
	}

	public T getProduct() {
		return product;
	}

	public void setProduct(T product) {
		this.product = product;
	}
}
