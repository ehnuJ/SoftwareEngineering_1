!DOCTYPE html>
<html>
<head>
        <h1>EECS 348 Lab Seven Practice Four</h1>
</head>
<body>
        <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
                <label for="num">Enter a number:</label>
                <input type="number" name="num" id="num">
                <input type="submit" value="Generate Table">
        </form>
        <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $num = $_POST["num"];
                echo "<table border='1'>";
                echo "<tr><th>&nbsp;</th>";
                for ($i = 1; $i <= $num; $i++) {
                        echo "<th>$i</th>";
                }
                echo "</tr>";
                for ($i = 1; $i <= $num; $i++) {
                        echo "<tr>";
                echo "<th>$i</th>";
                        for ($j = 1; $j <= $num; $j++) {
                                echo "<td>" . ($i * $j) . "</td>";
                        }
                        echo "</tr>";
                }
                echo "</table>";
        }
        ?>
</body>
</html>