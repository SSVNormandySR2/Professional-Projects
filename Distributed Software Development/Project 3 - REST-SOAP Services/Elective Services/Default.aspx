<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="ElectiveServicesTryIt._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>Elective Counting Services TryIt Page</h1>
        <p class="lead">This TryIt page allows for testing of the WordCount, CharacterCount, SpecialCharacterCount, and CountOccurrences services.</p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>StringWordCount Service</h2>
            <p>
                This service counts the number of words in a given input string.</p>
            <p>
                Operation Name: StringWordCount</p>
            <p>
                Parameter types: string input for words to be counted</p>
            <p>
                Return type: int for number of words</p>
            <p>
                <asp:Label ID="wordPromptLabel" runat="server" Text="Enter a string of words to count: "></asp:Label>
                <asp:TextBox ID="inputString" runat="server" Width="323px"></asp:TextBox>
                <asp:Button ID="wordCountButton" runat="server" OnClick="wordCountButton_Click" Text="Count Words!" />
            </p>
            <p>
                <asp:Label ID="wordOutputLabel" runat="server" Text="Number of Words: "></asp:Label>
            </p>
        </div>
        <div class="col-md-4">
            <h2>CharacterCount Service</h2>
            <p>
                This service counts the number of characters in a given input string.</p>
            <p>
                Operation Name: CharacterCount</p>
            <p>
                Parameter types: string input for characters to be counted</p>
            <p>
                Return type: int for number of characters</p>
            <p>
                <asp:Label ID="charPromptLabel" runat="server" Text="Enter a string of characters to count: "></asp:Label>
                <asp:TextBox ID="inputChars" runat="server" Width="297px"></asp:TextBox>
                <asp:Button ID="charCountButton" runat="server" OnClick="charCountButton_Click" Text="Count Characters!" />
            </p>
            <p>
                <asp:Label ID="charOutputLabel" runat="server" Text="Number of Characters: "></asp:Label>
            </p>
        </div>
        <div class="col-md-4">
            <h2>SpecialCharacterCount Service</h2>
            <p>
                This service counts the number of special characters in a given input string. (i.e. !, @, #, $, %, ^, &amp;, *, (, ), etc.)</p>
            <p>
                Operation Name: SpecialCharacterCount</p>
            <p>
                
                Parameter types: string input for special characters to be counted</p>
            <p>
                
                Return type: int for number of special characters</p>
            <p>
                
                <asp:Label ID="specCharPromptLabel" runat="server" Text="Enter a string with special characters: "></asp:Label>
                <asp:TextBox ID="specInputChars" runat="server" Width="307px"></asp:TextBox>
                <asp:Button ID="specCharCountButton" runat="server" OnClick="specCharCountButton_Click" Text="Count Special Characters!" />
                
            </p>
            <p>
                
                <asp:Label ID="specCharOutputLabel" runat="server" Text="Number of Special Characters: "></asp:Label>
                
            </p>
        </div>
        <div class="col-md-4">
            <h2>CountOccurrences Service</h2>
            <p>

                This service counts the number of occurrences of a specific character in a given input string.</p>
            <p>

                Operation Name: CountOccurrences</p>
            <p>

                Parameter types: string input to check, character to look for</p>
            <p>

                Return type: int for number of occurrences</p>
            <p>

                <asp:Label ID="occurrenceStringPromptLabel" runat="server" Text="Enter a string to count occurrences: "></asp:Label>
                <asp:TextBox ID="occurrencesStringInput" runat="server" Width="329px"></asp:TextBox>
            </p>
            <p>

                <asp:Label ID="Label1" runat="server" Text="Enter a single character to count within the string: "></asp:Label>
                <asp:TextBox ID="occurrencesCharInput" runat="server" Width="53px"></asp:TextBox>
                <asp:Button ID="occurrenceCountButton" runat="server" OnClick="occurrenceCountButton_Click" Text="Count Character Occurrences!" />
            </p>
            <p>

                <asp:Label ID="occurrenceOutputLabel" runat="server" Text="Number of Occurrences: "></asp:Label>
            </p>
        </div>
    </div>

</asp:Content>
