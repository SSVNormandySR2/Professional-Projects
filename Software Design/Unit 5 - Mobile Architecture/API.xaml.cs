/*
 * Vincent Latona
 */

namespace IdealWeightCalculator.Views;

public partial class API : ContentPage
{
	public API()
	{
		InitializeComponent();
		BindingContext = new IdealWeightCalculator.ViewModels.APIViewModel(); //Bind to VM
	}
}